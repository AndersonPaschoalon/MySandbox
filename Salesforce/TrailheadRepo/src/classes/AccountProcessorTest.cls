@IsTest
public class AccountProcessorTest {
	@IsTest
	private static void test_countContacts()
	{
		Account acc = new Account(Name='TestAcc');
		Contact ccc = new Contact(AccountId=acc.Id, FirstName='Fn', LastName='Ln');
		insert acc;	
		insert ccc;
		List<Id> listAccountIds = new List<Id>{acc.Id};

		Test.startTest();
		AccountProcessor.countContacts(listAccountIds);
		Test.stopTest();
	}
}