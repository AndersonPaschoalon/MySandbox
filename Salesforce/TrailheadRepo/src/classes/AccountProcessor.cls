public class AccountProcessor {

	@future
	public static void countContacts(List<Id> listAccountIds)
	{
		List<Account> listAccount = [SELECT Id,Name,Number_of_Contacts__c,(SELECT Id, Name FROM Contacts) FROM Account WHERE Id=:listAccountIds];
		for(Account acc : listAccount)
		{
			acc.Number_of_Contacts__c = acc.Contacts.size();
		}
		update listAccount;
	}
}