/**
 * Trailhead: https://trailhead.salesforce.com/pt-BR/trails/force_com_dev_advanced/modules/apex_patterns_dsl/units/apex_patterns_dsl_apply_dl_principles?trailmix_creator_id=00550000006gvuAAAQ&trailmix_id=gri-newemployee
 *-----------------------------------------------------------------------------------------------------------
 *  # Implement a basicDomain c = lass and Apex trigger
 *    Implement a basic Domain class and accompanying Apex trigger with default and update logic 
 *  based upon domain conventions.
 *  * Create a basic Domain class named Accounts that extends fflib_SObjectDomain.
 *  * Create a trigger named AccountsTrigger for Account that calls the fflib_SObjectDomain
 *    triggerHandler method for all trigger methods.
 *  * Implement defaulting logic that executes when a record is inserted and sets the 
 *    Description field to the value `Domain classes rock!`
 *  * Implement update logic that calculates the Levenshtein distance between the phrase
 *    Domain classes rock! and whatever the contents of the Description field is when an 
 *    Account is updated. Use the Apex String method getLevenshteinDistance(stringToCompare)
 *    and store the result in the Annual Revenue field.
 */

//  * Create a basic Domain class named Accounts that extends fflib_SObjectDomain.
public class Accounts extends fflib_SObjectDomain 
{

	/* 
	 * 
	 */
    public Accounts(List<Account> sObjectList) 
    {
        super(sObjectList);
    }


	/* 
	 * Constructor used by the trigger handler
	 *  * Create a trigger named AccountsTrigger for Account that calls the fflib_SObjectDomain
     *    triggerHandler method for all trigger methods.
	 */
    public class Constructor implements fflib_SObjectDomain.IConstructable 
    {
        public fflib_SObjectDomain construct(List<SObject> sObjectList) 
        {
            return new Accounts(sObjectList);
        }
    }

    /* 
     * Trailhead examples
     */
    public void updateOpportunityActivity(fflib_SObjectUnitOfWork uow) 
    {
        for(Account account : (List<Account>) Records) 
        {
            account.Description = 'Last Opportunity Raised ' + System.today();
            uow.registerDirty(account);
        }
    }

	//  * Implement defaulting logic that executes when a record is inserted and sets the 
	//    Description field to the value `Domain classes rock!`
	public override void onApplyDefaults() 
	{
	    // Apply defaults to Opportunities
	    for(Account theAccount : (List<Account>) Records) 
	    {
	        if(theAccount.Description == null) 
	        {
	            theAccount.Description = 'Domain classes rock!';
	        }               
	    }
	}

	//  * Implement update logic that calculates the Levenshtein distance between the phrase
	//    Domain classes rock! and whatever the contents of the Description field is when an 
	//    Account is updated. Use the Apex String method getLevenshteinDistance(stringToCompare)
	//    and store the result in the Annual Revenue field.
	public override void onBeforeUpdate(Map<Id,SObject> existingRecords) 
	{
	    // Validate changes to Opportunities
	    for(Account singleAccount : (List<Account>) Records) 
	    {
	    	String accountDescription = singleAccount.Description;
	    	Integer levenshteinDistance = accountDescription.getLevenshteinDistance('Domain classes rock!');
	    	singleAccount.AnnualRevenue = levenshteinDistance;

	    }
	}


}