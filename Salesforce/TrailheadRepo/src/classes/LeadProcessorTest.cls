@isTest
private class LeadProcessorTest {
	
	@isTest static void test_method_one() {
        Test.startTest();
        LeadProcessor lp = new LeadProcessor();
        Id batchId = Database.executeBatch(lp);
        Test.stopTest();

		List<Lead> leadBatchData = [SELECT Id,FirstName, LastName, LeadSource FROM Lead];
		for(Lead ld: leadBatchData)
		{
			System.assertEquals('Dreamforce', ld.LeadSource, 'Lead Source was not updated');
		}
	}
	
	 @testSetup static void buildData() {
		Integer nLeads = 200;
		List<Lead> listLeads = new List<Lead>();
		for(Integer i=0; i<nLeads; i++)
		{
			Lead newLead = new Lead(FirstName='Fn-'+i, LastName='Ln-'+i, LeadSource='test-data', Company='TestCompany' );
			listLeads.add(newLead);
		}
		insert listLeads; 
	}

	
}