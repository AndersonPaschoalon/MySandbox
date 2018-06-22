// Create a Selector class for the Account object named AccountsSelector with a selectById 
// method that accepts a set of Ids and returns a list of Accounts. Configure the Selector 
// base class functionality to retrieve the fields Name, Description, and AnnualRevenue.
public class AccountsSelector extends fflib_SObjectSelector
{
	public AccountsSelector() 
	{
        super(false);
    }
    
    public AccountsSelector(Boolean includeFieldSetFields) 
    {
        super(includeFieldSetFields);
    }

    public List<Schema.SObjectField> getSObjectFieldList() 
    {
        return new List<Schema.SObjectField> 
        {	Account.Id,
            Account.Name,
            Account.Description,
            Account.AnnualRevenue };
    }

    public Schema.SObjectType getSObjectType() 
    {
        return Account.sObjectType;
    }

    public List<Account> selectById(Set<ID> idSet) 
    {
        return (List<Account>) selectSObjectsById(idSet);
    }    
}