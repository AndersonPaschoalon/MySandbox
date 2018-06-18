@IsTest
public class UnitOfWorkTest 
{
	@IsTest
	public static void example_run_test_1() 
	{
		List<Opportunity> opps = new List<Opportunity>();
		List<List<Product2>> productsByOpp = new List<List<Product2>>();
		List<List<PricebookEntry>> pricebookEntriesByOpp = new List<List<PricebookEntry>>();
		List<List<OpportunityLineItem>> oppLinesByOpp = new List<List<OpportunityLineItem>>();
		for(Integer o=0; o<10; o++) {
		    Opportunity opp = new Opportunity();
		    opp.Name = 'Opportunity ' + o;
		    opp.StageName = 'Open';
		    opp.CloseDate = System.today();
		    opps.add(opp);
		    List<Product2> products = new List<Product2>();
		    List<PricebookEntry> pricebookEntries = new List<PricebookEntry>();
		    List<OpportunityLineItem> oppLineItems = new List<OpportunityLineItem>();
		    for(Integer i=0; i<o+1; i++) {
		        Product2 product = new Product2();
		        product.Name = opp.Name + ' : Product : ' + i;
		        products.add(product);
		        PricebookEntry pbe = new PricebookEntry();
		        pbe.UnitPrice = 10;
		        pbe.IsActive = true;
		        pbe.UseStandardPrice = false;
		        pbe.Pricebook2Id = Test.getStandardPricebookId();
		        pricebookEntries.add(pbe);
		        OpportunityLineItem oppLineItem = new OpportunityLineItem();
		        oppLineItem.Quantity = 1;
		        oppLineItem.TotalPrice = 10;
		        oppLineItems.add(oppLineItem);
		    }
		    productsByOpp.add(products);
		    pricebookEntriesByOpp.add(pricebookEntries);
		    oppLinesByOpp.add(oppLineItems);
		}
		// Insert Opportunities
		insert opps;
		// Insert Products
		List<Product2> allProducts = new List<Product2>();
		for(List<Product2> products : productsByOpp) {
		    allProducts.addAll(products);
		}
		insert allProducts;
		// Insert Pricebooks
		Integer oppIdx = 0;
		List<PricebookEntry> allPricebookEntries = new List<PricebookEntry>();
		for(List<PriceBookEntry> pricebookEntries : pricebookEntriesByOpp) {
		    List<Product2> products = productsByOpp[oppIdx++];
		    Integer lineIdx = 0;
		    for(PricebookEntry pricebookEntry : pricebookEntries) {
		        pricebookEntry.Product2Id = products[lineIdx++].Id;
		    }
		    allPricebookEntries.addAll(pricebookEntries);
		}
		insert allPricebookEntries;
		// Insert Opportunity Lines
		oppIdx = 0;
		List<OpportunityLineItem> allOppLineItems = new List<OpportunityLineItem>();
		for(List<OpportunityLineItem> oppLines : oppLinesByOpp) {
		    List<PricebookEntry> pricebookEntries = pricebookEntriesByOpp[oppIdx];
		    Integer lineIdx = 0;
		    for(OpportunityLineItem oppLine : oppLines) {
		        oppLine.OpportunityId = opps[oppIdx].Id;
		        oppLine.PricebookEntryId = pricebookEntries[lineIdx++].Id;
		    }
		    allOppLineItems.addAll(oppLines);
		    oppIdx++;
		}
		insert allOppLineItems;
		System.debug('opps.size()='+opps.size());
		System.debug('allProducts.size()='+allProducts.size());
		System.debug('allPricebookEntries.size()='+allPricebookEntries.size());
		System.debug('allOppLineItems.size()='+allOppLineItems.size());
	}

	@IsTest
	public static void example_run_fflib()
	{
		// Create a Unit Of Work
		fflib_SObjectUnitOfWork uow = new fflib_SObjectUnitOfWork(
		    new Schema.SObjectType[] {
		        Product2.SObjectType,
		        PricebookEntry.SObjectType,
		        Opportunity.SObjectType,
		        OpportunityLineItem.SObjectType
		    }
		);

		// Do some work!
		for(Integer o=0; o<10; o++) {
		    Opportunity opp = new Opportunity();
		    opp.Name = 'UoW Test Name ' + o;
		    opp.StageName = 'Open';
		    opp.CloseDate = System.today();
		    uow.registerNew(opp);
		    for(Integer i=0; i<o+1; i++) {
		      Product2 product = new Product2();
		      product.Name = opp.Name + ' : Product : ' + i;
		      uow.registerNew(product);
		      PricebookEntry pbe = new PricebookEntry();
		      pbe.UnitPrice = 10;
		      pbe.IsActive = true;
		      pbe.UseStandardPrice = false;
		      pbe.Pricebook2Id = Test.getStandardPricebookId();
		      uow.registerNew(pbe, PricebookEntry.Product2Id, product);
		      OpportunityLineItem oppLineItem = new OpportunityLineItem();
		      oppLineItem.Quantity = 1;
		      oppLineItem.TotalPrice = 10;
		      uow.registerRelationship(oppLineItem, OpportunityLineItem.PricebookEntryId, pbe);
		      uow.registerNew(oppLineItem, OpportunityLineItem.OpportunityId, opp);
		    }
		}

		// Commit the work to the database!
		uow.commitWork();

		 // Inserts new Opportunity when committing
		//uow.registerNew(opp);
		// Inserts new Opportunity Line Item and associates it with the given Opportunity record when committing
		//uow.registerNew(oppLineItem, OpportunityLineItem.OpportunityId, opp);
		// Relates the given Opportunity Line Item to the given Price Book Entry when committing
		//uow.registerRelationship(oppLineItem, OpportunityLineItem.PricebookEntryId, pbe);
	}

	@isTest
	public static void challengeComplete()
	{
		// Create a Unit Of Work
		fflib_SObjectUnitOfWork uow = new fflib_SObjectUnitOfWork(
	    		new Schema.SObjectType[] {
		        Account.SObjectType,
		        Contact.SObjectType,
		        Note.SObjectType
		    }
		);

		// Do some work!
		for(Integer iAcc=0; iAcc<100; iAcc++) 
		{
		    Account theAccount = new Account(Name='UoW Test Account ' + iAcc);
		    uow.registerNew(theAccount);
		    for(Integer iCc=0; iCc<5; iCc++) 
		    {
				// -> atentar para: o segundo argumento de fflib_SObjectUnitOfWork.registerRelationship()
				//		e fflib_SObjectUnitOfWork.registerNew() não é uma variavel

		    	// Contact
		    	Contact theContact = new Contact(LastName='Uow Contact '+ theAccount.Name + '::' +iCc);
				uow.registerRelationship(theContact, Contact.AccountId, theAccount);
				uow.registerNew(theContact, Contact.AccountId, theAccount);
				// Note
				Note theNote = new Note(Title='Uow Note iAcc:' + iAcc , Body = 'Test note body.');
				uow.registerRelationship(theNote, Note.ParentId, theAccount);
				uow.registerNew(theNote, Note.ParentId, theAccount);
		    }
		}

		// Commit the work to the database!
		uow.commitWork();

		System.assertEquals(100, [Select Id from Account].size());
		System.assertEquals(500, [Select Id from Contact].size());
		System.assertEquals(500, [Select Id from Note].size());
	}
}