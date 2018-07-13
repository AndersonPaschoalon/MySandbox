global class LeadProcessor implements Database.Batchable<sObject> {
	
	String query;
	
	global LeadProcessor() {
		
	}
	
	global Database.QueryLocator start(Database.BatchableContext BC) {
		this.query = 'SELECT Id, Name, LeadSource FROM Lead';
		return Database.getQueryLocator(query);
	}

   	global void execute(Database.BatchableContext BC, List<Lead> scope) {
		for(Lead ld:scope)
		{
			ld.LeadSource = 'Dreamforce';
		}
		update scope;
	}
	
	global void finish(Database.BatchableContext BC) {
		
	}
	
}