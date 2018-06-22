public class ContactsListController {
    private String sortOrder = 'LastName';
        
    public List<Contact> getContacts() {
        
        List<Contact> results = Database.query(
            'SELECT Id, FirstName, LastName, Title, Email ' +
            'FROM Contact ' +
            'ORDER BY ' + sortOrder + ' ASC ' +
            'LIMIT 10'
        );
        return results;
    }
    public void sortByLastName() {
        this.sortOrder = 'LastName';
    }
        
    public void sortByFirstName() {
        this.sortOrder = 'FirstName';
    }
    
    public List<Integer> getTabuada()
    {
        Integer i = 0;
        List<Integer> tab = new List<Integer>();
        for(i = 0; i <= 10; i++)
        {
            tab.add(i*7);
        }
        return tab;
    }
}