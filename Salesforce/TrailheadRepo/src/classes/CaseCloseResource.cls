// *  Create a REST Apex class called CaseCloseResource with a URL mapping /case/*/
//   close (where * will be the Id). 
@RestResource(urlMapping='/case/*/close')
global  with sharing class CaseCloseResource {

	// Implement a POST closeCase method which accepts 
	// a String reason and calls the CaseService.closeCases service method passing in 
	// the Id and close reason.
    @HttpPost
    global static void closeCase(String reason)
    {
        // Parse context
        RestRequest req = RestContext.request;
        String[] uriParts = req.requestURI.split('/');
        Id caseId = uriParts[2];
        // Call the service
        CaseService.closeCases(
            new Set<ID> { caseId }, reason);         	
    }
}