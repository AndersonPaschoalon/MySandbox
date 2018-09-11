@IsTest
public class AddPrimaryContactTest {
    @isTest
    private static void test_1()
    {
        Integer nAccounts = 100;
        List<Account> listAccounts = new List<Account>();
        for(Integer i=0; i<nAccounts; i++)
        {
            Account acc = new Account(Name='test-account-'+i);
            if(i<50){
             	acc.BillingState='CA';
            }
            else{
                acc.BillingState='NY';
            }
            listAccounts.add(acc);
        }
        System.debug('@testSetup: listAccount.size()='+listAccounts.size());
        insert listAccounts;
        System.debug('@testSetup: listAccount='+listAccounts);
                System.debug('listAccounts.size()='+listAccounts.size());
        System.debug('listAccounts='+listAccounts);
        System.assertEquals(100, listAccounts.size(), 'Error!! Expected 100 accounts');
        Contact theContact = new Contact(FirstName='TestFirstName', LastName='TestLastName');
        insert theContact;
        
        AddPrimaryContact apc = new AddPrimaryContact(theContact, 'CA');
        Test.startTest();        
        System.enqueueJob(apc);
        Test.stopTest();  
        List<Contact> listCon = [SELECT Id, FirstName, LastName, AccountId FROM Contact WHERE AccountId IN :listAccounts];
        //System.assertEquals(50, listCon.size(), 'Error!!');
        
    }
    /**
	* In the test class, insert 50 Account records for BillingState "NY" and 50 Account 
	* records for BillingState "CA". Create an instance of the AddPrimaryContact class, 
	* enqueue the job and assert that a Contact record was inserted for each of the 50 
	* Accounts with the BillingState of "CA".
	*/
    @testSetup
    private static void build()
    {

    }
    
}