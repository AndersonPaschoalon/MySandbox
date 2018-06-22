public class AccountHandler {
    public static Account insertNewAccount(String accName)
    {
        try {
            if(accName != '')
            {
                // This causes an exception because 
                //   the required Name field is not provided.
                Account acct = new Account(Name=accName);
                // Insert the account 
                insert acct;
                return acct;
            }
            else
            {
                return NULL;
            }

        } catch (DmlException e) {
            System.debug('A DML exception has occurred: ' +
                         e.getMessage());
            return NULL;
        }
    }

}