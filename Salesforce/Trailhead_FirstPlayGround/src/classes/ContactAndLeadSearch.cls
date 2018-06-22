public class ContactAndLeadSearch {
    public static List<List<SObject>> searchContactsAndLeads(String theSearchkey)
    {
        //List<List<sObject>> searchList = [FIND 'Smith' IN ALL FIELDS RETURNING Contact(LastName),Lead(LastName)];
        List<List<sObject>> searchList = [FIND :theSearchkey IN ALL FIELDS RETURNING Contact(LastName),Lead(LastName)];

        return searchList;
    }
/*
    public static List<List<SObject>> searchContactsAndLeads(String keyword)
    {
        List<List<sObject>> searchList = [FIND {keyword} IN NAME FIELDS RETURNING Contact(LastName), Lead(LastName)];
        
        return searchList;
    }

    public static List<List<SObject>> searchContactsAndLeads()
    {
        String keyword = 'Smith';
        System.debug('in the function searchContactsAndLeads()');
        List<List<SObject>> searchList = [FIND keyword IN NAME FIELDS RETURNING Contact(LastName), Lead(LastName)];
        
        return searchList;
    }
*/

    public static void test()
    {
        System.debug('TESTE TESTE ADSASDAD');
    }
}