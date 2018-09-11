public class RandomContactFactory {

	public static List<Contact> generateRandomContacts(Integer nContacts, String lastName)
    {
        List<Contact> listContacts = new List<Contact>();
        for(Integer i=0; i<nContacts; i++)
        {
            String firstName = String.valueOf(i)+'-'+lastName;
            Contact con = new Contact(FirstName=firstName, LastName=lastName);
            listContacts.add(con);
        }
        return listContacts;
    }
}