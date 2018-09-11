public class AddPrimaryContact implements Queueable
{
    private List<Contact> primaryContacts;
    
    public AddPrimaryContact(Contact con, String stateAbbreviation)
    {
        List<Account> listAccounts = [SELECT Id, Name, BillingState FROM Account WHERE BillingState=:stateAbbreviation LIMIT 200];
        System.debug('Accounts to update: listAccounts.size()='+listAccounts.size());
        this.primaryContacts = new List<Contact>();
        for(Account acc:listAccounts)
        {
            Contact newContact = con.clone(false, true, true, true);
            newContact.AccountId = acc.Id;
            this.primaryContacts.add(newContact);
        }
        System.debug('this.primaryContacts.size():'+this.primaryContacts.size());
    }
    
    public void execute(QueueableContext context) 
    {
        System.debug('Contacts to add: this.primaryContacts.size()='+this.primaryContacts.size());
		insert this.primaryContacts;
    }
}