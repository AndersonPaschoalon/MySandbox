global class DailyLeadProcessor implements Schedulable 
{
    global void execute(SchedulableContext ctx) {
        List<Lead> listLeads = [SELECT Id, Name, LeadSource FROM Lead WHERE LeadSource='' LIMIT 200];
        for(Lead ld:listLeads)
            ld.LeadSource='Dreamforce';
        update listLeads;
    }

}