@isTest
public class TestVerifyDate {
    @isTest static void test_datawithin30days() {
		Date myDate = Date.today();
        myDate.addDays(2);
        Date dataRet = VerifyDate.CheckDates(Date.today(), myDate);
        
        System.assertEquals(dataRet, myDate);
    }

    @isTest static void test_datamore30days() {
        Date myDateOriginal = Date.newInstance(2017, 4, 05);
        Date myDate = myDateOriginal.addDays(38);

        Date dataRet = VerifyDate.CheckDates(myDateOriginal.addDays(30), myDate);
        System.assertEquals(dataRet, myDate);
    }
    
    @isTest static void test_datafrompast() {
        Date myDate = Date.newInstance(1960, 2, 17);
        Date fakeToday =  Date.newInstance(2018, 2, 12);
        Date fakeEndOfMonth =  Date.newInstance(2018, 2, 28);
        
        Date dataRet = VerifyDate.CheckDates(fakeToday, myDate);
        System.assertEquals(dataRet, fakeEndOfMonth);
    }
    
}