({
	packItem : function(component, event, helper) {
		console.log("Hello log!");
        component.set("v.item.Packed__c", True);     // update our message
        component.set("v.disabled", True);
        

        
	}
})