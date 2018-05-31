// Create a public Apex class called UpdateContactPageLayout.
public with sharing class UpdateContactPageLayout {

	// Add a public method called addLayoutItem to the class. The method returns Metadata.Layout and takes no parameters.
	public Metadata.Layout addLayoutItem()
	{
		// In the addLayoutItem method, retrieve the metadata for the Contact page layout,
		// by using the Metadata.Operations.retrieve method. 
		// Assign the metadata retrieved to a variable called layoutsList that's a list of
		// Metadata.Metadata objects.
        List<Metadata.Metadata> layoutsList  = 
            Metadata.Operations.retrieve(Metadata.MetadataType.Layout, 
            new List<String> {'Contact-Contact Layout'});

        // Get the first layout in the list and assign it to a variable named layoutMetadata of type 
        // Metadata.Layout.
        Metadata.Layout layoutMetadata  = (Metadata.Layout) layoutsList.get(0);    

        // Create a variable called contactLayoutSection of type 
        // Metadata.LayoutSection and set it to null.
        Metadata.LayoutSection contactLayoutSection  = NULL;

        // Use the layoutSections property of layoutMetadata to iterate through the layout sections 
        // to find the section named Additional Information. 
        // Assign this section to contactLayoutSection.
        List<Metadata.LayoutSection> layoutSections = layoutMetadata.layoutSections;
        for (Metadata.LayoutSection section : layoutSections) {
            
            if (section.label == 'Additional Information') {
                contactLayoutSection = section;
                break;
            }
        }

        // Create a variable called contactColumns that's a list of Metadata.LayoutColumn objects. 
        // Use the layoutColumns property on contactLayoutSection to assign columns to contactColumns.
        List<Metadata.LayoutColumn>  contactColumns = contactLayoutSection.layoutColumns;

        // Create a variable called contactLayoutItems that's a list of Metadata.LayoutItem objects. 
        // Assign a value to this variable by using the layoutItems property on the first element in 
        // the contactColumns list.
        List<Metadata.LayoutItem> contactLayoutItems  = contactColumns.get(0).layoutItems;

        // Create an object called newField of type Metadata.LayoutItem.
        Metadata.LayoutItem  newField = new Metadata.LayoutItem();

        // Assign the following values to the new field:
		//		behavior: Metadata.UiBehavior.Edit
		//		field: 'AMAPI__Apex_MD_API_Twitter_name__c'
		// Add the new field to the contactLayoutItems metadata. Return layoutMetadata.
        newField.behavior = Metadata.UiBehavior.Edit;
        newField.field = 'AMAPI__Apex_MD_API_Twitter_name__c';
        contactLayoutItems.add(newField);

        return layoutMetadata;
	}


}