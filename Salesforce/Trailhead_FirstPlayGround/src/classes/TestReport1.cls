public class TestReport1 {
	
    public List<Integer> test_vectorx()
    {
        List<Integer> ll = new List<Integer>();
        for(Integer i = 0; i < 10; i++)
        {
            ll.add(i);
        }
        return ll;
    }
        public List<Integer> test_vectory()
    {
        List<Integer> ll = new List<Integer>();
        for(Integer i = 0; i < 10; i++)
        {
            ll.add(i*i);
        }
        return ll;
    }

}