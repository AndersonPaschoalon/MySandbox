public class ProductsSelector extends fflib_SObjectSelector 
{
	public ProductsSelector() 
	{
        super(false);
    }
    public ProductsSelector(Boolean includeFieldSetFields) 
    {
        super(includeFieldSetFields);
    }
    // classes/ProductsSelector.cls: Variable does not exist: MyFieldSet (Line: 14, Column: 50)
    //public override List<Schema.FieldSet> getSObjectFieldSetList() 
    //{
    //    return new List<Schema.FieldSet>
    //            { SObjectType.Product2.FieldSets.MyFieldSet };
    //}

    ////////////////////////////////////////////////////////////////

    public List<Schema.SObjectField> getSObjectFieldList() 
    {
        return new List<Schema.SObjectField> 
        {	Product2.Description,
            Product2.Id,
            Product2.IsActive,
            Product2.Name,
            Product2.ProductCode };
    }
    public Schema.SObjectType getSObjectType() 
    {
        return Product2.sObjectType;
    }
    public List<Product2> selectById(Set<ID> idSet) 
    {
        return (List<Product2>) selectSObjectsById(idSet);
    }
    public override String getOrderBy() 
    {
    	return 'IsActive DESC, ProductCode';
	}

	public List<Product2> selectRecentlyUpdated(Integer recordLimit) {   
	    return (List<Product2>) Database.query(
	        /**
	          Query factory has been pre-initialised by calling
	          getSObjectFieldList(), getOrderBy() for you.
	        */
	        newQueryFactory().
	        /**
	          Now focus on building the remainder of the
	          query needed for this method.
	        */
	        setCondition('SystemModstamp = LAST_N_DAYS:30').
	        setLimit(recordLimit).
	        // Finally build the query to execute
	        toSOQL());
	}

}
