// * Create an Apex class that is a service that exposes a bulkified service 
//   method. The service closes and sets the reason for one or more given case 
//   records. Implement an Apex REST class that calls this service.
public with sharing class CaseService {
	public CaseService() {
		// nothing to do
	}

	// *  Create an Apex class called CaseService that contains a void static method 
	//    called closeCases that takes a set of Case IDs and a String parameter for the 
	//    close reason.
	public static void closeCases(Set<Id> psCaseIds, String closeReason)
	{
		// validate input parameters
		if( (psCaseIds == NULL) || (psCaseIds.size()==0))
			throw new CaseServiceException('No cases specified');

		// validate input parameters
		//if( (closeReason == NULL))
		//	closeReason = 'not specified';


		List<Case> theCases = [SELECT Id,Status,Reason FROM Case WHERE Id IN :psCaseIds];
		for(Case singleCase:theCases)
		{
			singleCase.Status = 'Closed';
			singleCase.Reason = closeReason;
		}

		// save point
        SavePoint sp = Database.setSavePoint();
        try {
            update theCases;
            System.debug('Cases where rightly updated');
        } catch (Exception e) {
            // Rollback
            Database.rollback(sp);
            // Throw exception on to caller
            throw e;
        }  		

	}

	public class CaseServiceException extends Exception {} 
}