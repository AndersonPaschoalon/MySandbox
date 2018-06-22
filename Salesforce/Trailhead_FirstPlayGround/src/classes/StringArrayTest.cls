/**
 * Banco de dados e noções básicas do Apex
 */
public class StringArrayTest {
	public static List<String> generateStringArray(Integer n)
    {
        List<String> testList = new List<String>();
        for(Integer i = 0; i < n; i++)
        {
            //String sInteger = String.valueOf(myInteger);
            testList.add('Test ' + String.valueOf(i));
        }
        System.debug(testList);

        return testList;
    }
}