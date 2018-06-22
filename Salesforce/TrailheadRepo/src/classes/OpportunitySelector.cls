public class OpportunitySelector extends fflib_SObjectSelector
{

	public List<Opportunity> selectRecentlyUpdated(Integer recordLimit) {
	    String query = String.format(
	    'select {0} from {1} ' +
	    'where SystemModstamp = LAST_N_DAYS:30 ' +
	    'order by {2} limit {3}',
	    new List<String> {
	        getFieldListString(),
	        getSObjectName(),
	        getOrderBy(),
	        String.valueOf(recordLimit)
	      }
	    );
	    return (List<Opportunity>) Database.query(query);
	}

    public List<Schema.SObjectField> getSObjectFieldList() 
    {
        return new List<Schema.SObjectField> 
        {	Opportunity.StageName,
            Opportunity.Id,
            Opportunity.Name };
    }

    public Schema.SObjectType getSObjectType() 
    {
        return Product2.sObjectType;
    }

    public List<Product2> selectById(Set<ID> idSet) 
    {
        return (List<Product2>) selectSObjectsById(idSet);
    }

	public List<OpportunityInfo> selectOpportunityInfo(Set<Id> idSet) 
	{
	    List<OpportunityInfo> opportunityInfos = new List<OpportunityInfo>();
	    for(Opportunity opportunity : Database.query(
	            newQueryFactory(false).
	                selectField(Opportunity.Id).
	                selectField(Opportunity.Amount).
	                selectField(Opportunity.StageName).
	                selectField('Account.Name').
	                selectField('Account.AccountNumber').
	                selectField('Account.Owner.Name').
	                setCondition('id in :idSet').
	                toSOQL()))
	        opportunityInfos.add(new OpportunityInfo(opportunity));
	    return opportunityInfos;
	}
	
	public class OpportunityInfo 
	{       
	    private Opportunity opportunity;
	    public Id Id { get { return opportunity.Id; } }     
	    public Decimal Amount { get { return opportunity.Amount; } }        
	    public String Stage { get { return opportunity.StageName; } }       
	    public String AccountName { get { return opportunity.Account.Name; } }      
	    public String AccountNumber { get { return opportunity.Account.AccountNumber; } }       
	    public String AccountOwner { get { return opportunity.Account.Owner.Name; } }
	    private OpportunityInfo(Opportunity opportunity) { this.opportunity = opportunity; }         
	}


}