@IsTest
public class DailyLeadProcessorTest 
{
    public static String CRON_EXP = '0 0 0 15 3 ? 2022';
	@isTest
    private static void test()
    {
        Integer nLeads=200;
        List<Lead> listLeads = new List<Lead>();
        for(Integer i=0; i<nLeads; i++)
        {
            Lead newLead = new Lead(LeadSource='', LastName='Test-lastName', Company='BK');
            listLeads.add(newLead);
        }
        insert listLeads;
        Test.startTest();
        String jobId = System.schedule('ScheduledApexTest', CRON_EXP, new DailyLeadProcessor());
        Test.stopTest();
    }
    
}