import os
import time

import requests
from msal import ConfidentialClientApplication


class OneDriveClient:

    def __init__(
        self, user_id: str, client_id: str, tenant_id: str, client_secret: str
    ):
        self.user_id = user_id
        self.client_id = client_id
        self.tenant_id = tenant_id
        self.client_secret = client_secret
        self.authority = f"https://login.microsoftonline.com/{tenant_id}"
        self.app = ConfidentialClientApplication(
            client_id, authority=self.authority, client_credential=client_secret
        )
        self.scopes = ["https://graph.microsoft.com/.default"]

    def get_access_token(self):
        result = self.app.acquire_token_silent(self.scopes, account=None)

        if not result:
            result = self.app.acquire_token_for_client(scopes=self.scopes)

        if result and "access_token" not in result:
            raise Exception(f"Erro ao obter token: {result.get('error_description')}")
        return result["access_token"] if result else None

    def upload(self, local_file: str, one_drive_path: str, replace: bool = False):
        onedrive_path = f"{one_drive_path}/{local_file}"
        if not os.path.exists(local_file):
            raise FileNotFoundError(local_file)

        # Endpoint Graph
        upload_url = f"https://graph.microsoft.com/v1.0/users/{user_id}/drive/root:/{onedrive_path}:/content"
        token = self.get_access_token()

        if replace == True:
            self._del_if_exist_on_dir(local_file, one_drive_path)

        # Upload
        with open(local_file, "rb") as file:
            response = requests.put(
                upload_url,
                headers={"Authorization": f"Bearer {token}"},
                data=file,
            )

        if response.status_code in (200, 201):
            print("Upload realizado com sucesso!")
            print("Arquivo ID:", response.json()["id"])
        else:
            print("Erro no upload:", response.status_code, response.text)

    def ls(self, folder_path: str):
        """Lista todos os arquivos do OneDrive dentro da pasta especificada."""
        token = self.get_access_token()
        url = f"https://graph.microsoft.com/v1.0/users/{user_id}/drive/root:/{folder_path}:/children"

        response = requests.get(url, headers={"Authorization": f"Bearer {token}"})
        response.raise_for_status()
        files = response.json().get("value", [])

        print(f"Arquivos encontrados em '{folder_path}':")
        for f in files:
            print(f" - {f['name']} ({f['id']})")

        return files

    def move_file(self, file_obj, new_folder_path, replace: bool = False):
        """Move o arquivo especificado para outra pasta."""
        item_id = file_obj["id"]
        token = self.get_access_token()
        url = f"https://graph.microsoft.com/v1.0/users/{self.user_id}/drive/items/{item_id}"

        # Obter ID da nova pasta destino
        dest_url = f"https://graph.microsoft.com/v1.0/users/{self.user_id}/drive/root:/{new_folder_path}"
        dest_resp = requests.get(dest_url, headers={"Authorization": f"Bearer {token}"})
        dest_resp.raise_for_status()
        dest_id = dest_resp.json()["id"]

        if replace:
            self._del_if_exist_on_dir(file_obj["name"], new_folder_path)

        payload = {"parentReference": {"id": dest_id}}
        response = requests.patch(
            url,
            headers={
                "Authorization": f"Bearer {token}",
                "Content-Type": "application/json",
            },
            json=payload,
        )
        if response.status_code in (200, 201):
            print(f"Arquivo movido para '{new_folder_path}'.")
            return True
        else:
            print(f"Erro ao mover arquivo: {response.status_code} {response.text}")
            return False

    def delete_file(self, file_obj):
        """Deleta o arquivo."""
        item_id = file_obj["id"]
        token = self.get_access_token()
        url = f"https://graph.microsoft.com/v1.0/users/{self.user_id}/drive/items/{item_id}"
        response = requests.delete(url, headers={"Authorization": f"Bearer {token}"})
        if response.status_code == 204:
            print(f"Arquivo {item_id} deletado com sucesso.")
            return True, "Arquivo {item_id} deletado com sucesso."
        else:
            print(f"Erro ao deletar arquivo: {response.status_code} {response.text}")
            return (
                False,
                f"Erro ao deletar arquivo: {response.status_code} {response.text}",
            )

    def _del_if_exist_on_dir(self, file_name: str, onedrive_folder: str):
        files_on_dir = self.ls(onedrive_folder)
        for f in files_on_dir:
            if file_name == f["name"]:
                self.delete_file(f)

    def download(self, file_obj, local_dir: str = "."):
        """
        Faz o download de um arquivo do OneDrive e o salva localmente.

        Args:
            file_obj (dict): Objeto retornado pelo método `ls()`, contendo pelo menos `id` e `name`.
            local_dir (str): Diretório local onde o arquivo será salvo. Default: diretório atual.

        Returns:
            str: Caminho completo do arquivo baixado em caso de sucesso.
        """
        token = self.get_access_token()
        item_id = file_obj["id"]
        file_name = file_obj["name"]
        local_path = os.path.join(local_dir, file_name)

        # Endpoint para download direto
        url = f"https://graph.microsoft.com/v1.0/users/{self.user_id}/drive/items/{item_id}/content"

        response = requests.get(
            url, headers={"Authorization": f"Bearer {token}"}, stream=True
        )

        if response.status_code == 200:
            os.makedirs(local_dir, exist_ok=True)
            with open(local_path, "wb") as f:
                for chunk in response.iter_content(chunk_size=8192):
                    if chunk:
                        f.write(chunk)
            print(f"⬇Download concluído: {local_path}")
            return local_path
        else:
            print(f"Erro ao baixar arquivo: {response.status_code} {response.text}")
            return None


testN = 4

user = "user@domain.com.br"
password = "user-password"
client_id = "client-id"
client_secret = "~client-secret~"
tenant_id = "tenant-id"
user_id = "user-id@domain.com.br"
onedrive = OneDriveClient(
    user_id=user_id,
    client_id=client_id,
    tenant_id=tenant_id,
    client_secret=client_secret,
)

if testN == 1:
    onedrive.upload("arquivo2.xlsx", "Folder/SubFolder")
    time.sleep(3)
    files = onedrive.ls("Folder/SubFolder")
    for f in files:
        if f["name"] == "arquivo2.xlsx":
            onedrive.move_file(f, "Folder/SubFolder/test")
elif testN == 2:
    files = onedrive.ls("Folder/SubFolder")
    for f in files:
        if f["name"] == "arquivo2.xlsx":
            onedrive.delete_file(f)
elif testN == 3:
    onedrive.upload("arquivo2.xlsx", "Folder/SubFolder", replace=True)
    time.sleep(3)
    files = onedrive.ls("Folder/SubFolder")
    for f in files:
        if f["name"] == "arquivo2.xlsx":
            onedrive.move_file(f, "Folder/SubFolder/test", replace=True)

if testN == 4:
    files = onedrive.ls("Folder/SubFolder/test")

    for f in files:
        if f["name"] == "arquivo2.xlsx":
            onedrive.download(f, local_dir="./d")
