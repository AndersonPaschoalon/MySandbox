({
    createItemForm : function (component, newItemToSave)
    {
        console.log("entrou no create helper FORM");
        var action = component.getEvent("addItem");
        console.log("criada a action helper");
        console.log("erro no helper FORM");
        action.setParams({
            "item": newItemToSave
        });
        console.log("erro no helper2  FORM");
        action.fire();

        component.set("v.newItem",{ 'sobjectType': 'Camping_Item__c',
                        'Name': '',
                        'Quantity__c': 0,
                        'Price__c': 0,
                        'Packed__c': false });

    },
})