public class TestDatabaseClass {
	public static void test1()
    {
        System.debug('Create sObject, insert account by DML');
        // Create the account sObject 
		Account acct = new Account(Name='Acme', Phone='(415)555-1212', NumberOfEmployees=100);
		// Insert the account by using DML
		insert acct;
    }
    
    public static void test2()
    {
        // Create the account sObject 
		Account acct = new Account(Name='Acme', Phone='(415)555-1212', NumberOfEmployees=100);
		// Insert the account by using DML
		insert acct;

		// Get the new ID on the inserted sObject argument
		ID acctID = acct.Id;
		// Display this ID in the debug log
		System.debug('ID = ' + acctID);
    }
    
    public static void test3()
    {
        // Create a list of contacts
		List<Contact> conList = new List<Contact> {
    		new Contact(FirstName='Joe',LastName='Smith',Department='Finance'),
        	new Contact(FirstName='Kathy',LastName='Smith',Department='Technology'),
        	new Contact(FirstName='Caroline',LastName='Roth',Department='Finance'),
       		new Contact(FirstName='Kim',LastName='Shain',Department='Education')};
            
		// Bulk insert all contacts with one DML call
		insert conList;

		// List to hold the new contacts to update
		List<Contact> listToUpdate = new List<Contact>();

		// Iterate through the list and add a title only
		//   if the department is Finance
		for(Contact con : conList) 
        {
    		if (con.Department == 'Finance') 
            {
        		con.Title = 'Financial analyst';
        		// Add updated contact sObject to the list.
        		listToUpdate.add(con);
    		}
		}

		// Bulk update all contacts with one DML call
		update listToUpdate;
    }
    
    public static void test4()
    {
        // Insert the Josh contact
        Contact josh = new Contact(FirstName='Josh',LastName='Kaplan',Department='Finance');       
        insert josh;
        
        // Josh's record has been inserted
        //   so the variable josh has now an ID
        //   which will be used to match the records by upsert
        josh.Description = 'Josh\'s record has been updated by the upsert operation.';
        
        // Create the Kathy contact, but don't persist it in the database
        Contact kathy = new Contact(FirstName='Kathy',LastName='Brown',Department='Technology');
        
        // List to hold the new contacts to upsert
        List<Contact> contacts = new List<Contact> { josh, kathy };
        
        // Call upsert
        upsert contacts;
        
        // Result: Josh is updated and Kathy is created.
    }
    
    public static void test5()
    {
        // Insert the Josh contact
        Contact josh = new Contact(FirstName='Josh',LastName='Kaplan',Department='Finance');       
        insert josh;
        
        // Josh's record has been inserted
        //   so the variable josh has now an ID
        //   which will be used to match the records by upsert
        josh.Description = 'Josh\'s record has been updated by the upsert operation.';
        
        // Create the Kathy contact, but don't persist it in the database
        Contact kathy = new Contact(FirstName='Kathy',LastName='Brown',Department='Technology');
        
        // List to hold the new contacts to upsert
        List<Contact> contacts = new List<Contact> { josh, kathy };
        
        // Call upsert
        upsert contacts;
        
        // Result: Josh is updated and Kathy is created.        
    }
    
    public static void test6()
    {
        try 
        {
            // This causes an exception because 
            //   the required Name field is not provided.
            Account acct = new Account();
            // Insert the account 
            insert acct;
        } 
        catch (DmlException e) 
        {
            System.debug('A DML exception has occurred: ' +
                        e.getMessage());
        }
    }

    // Exemplo: Inserindo registros com sucesso parcial
    public static void test7()
    {
        // Create a list of contacts
        List<Contact> conList = new List<Contact> {
                new Contact(FirstName='Joe',LastName='Smith',Department='Finance'),
                new Contact(FirstName='Kathy',LastName='Smith',Department='Technology'),
                new Contact(FirstName='Caroline',LastName='Roth',Department='Finance'),
                new Contact()};
                    
        // Bulk insert all contacts with one DML call
        Database.SaveResult[] srList = Database.insert(conList, false);
        
        // Iterate through each returned result
        for (Database.SaveResult sr : srList) {
            if (sr.isSuccess()) {
                // Operation was successful, so get the ID of the record that was processed
                System.debug('Successfully inserted contact. Contact ID: ' + sr.getId());
            } else {
                // Operation failed, so get all errors
                for(Database.Error err : sr.getErrors()) {
                    System.debug('The following error has occurred.');
                    System.debug(err.getStatusCode() + ': ' + err.getMessage());
                    System.debug('Contact fields that affected this error: ' + err.getFields());
             }
            }
        }
    }    
    
    // Trabalhando com registros relacionados
    public static void test8()
    {
        Account acct = new Account(Name='SFDC Account');
        insert acct;
        
        // Once the account is inserted, the sObject will be 
        // populated with an ID.
        // Get this ID.
        ID acctID = acct.ID;
        
        // Add a contact to this account.
        Contact mario = new Contact(
            FirstName='Mario',
            LastName='Ruiz',
            Phone='415.555.1212',
            AccountId=acctID);
        insert mario;
    }
    
    // Atualizando registros relacionados
	
    
	public static void test9()
    {
        List<List<sObject>> searchList = [FIND 'Wingo OR SFDC' IN ALL FIELDS 
                   RETURNING Account(Name),Contact(FirstName,LastName,Department)];
        Account[] searchAccounts = (Account[])searchList[0];
        Contact[] searchContacts = (Contact[])searchList[1];
        
        System.debug('Found the following accounts.');
        for (Account a : searchAccounts) {
            System.debug(a.Name);
        }
        
        System.debug('Found the following contacts.');
        for (Contact c : searchContacts) {
            System.debug(c.LastName + ', ' + c.FirstName);
        }
    }
    
        
// end of the class
}