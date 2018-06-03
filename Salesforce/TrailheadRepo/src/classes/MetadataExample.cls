// * Create a public Apex class called MetadataExample.
public class MetadataExample {
	// * Create a public method called updateMetadata that takes no arguments and returns void.
	public void updateMetadata()
	{
		// * Create an object called customMetadata of type Metadata.CustomMetadata.
		Metadata.CustomMetadata customMetadata = new Metadata.CustomMetadata();

		// * Set the fullName of the customMetadata object to be: 
		//   'MyNamespace__MyMetadataTypeName.MyMetadataRecordName'.
		customMetadata.fullName = 'MyNamespace__MyMetadataTypeName.MyMetadataRecordName';

		// * Create an object called customField of the type Metadata.CustomMetadataValue.
		Metadata.CustomMetadataValue customField = new Metadata.CustomMetadataValue();


		// * Set customField.field to 'customField__c'. Set customField.value to 'New value'.
		customField.field = 'customField__c';
		customField.value = 'New value';

		// * Add the customField object to the list of values in customMetadata.
		customMetadata.values.add(customField);

		// * Create an object called deployContainer of type Metadata.DeployContainer.
		Metadata.DeployContainer deployContainer = new Metadata.DeployContainer();

		// * Add customMetadata to deployContainer.
		deployContainer.addMetadata(customMetadata);

		// * Use the Metadata.Operations.enqueueDeployment method to deploy the metadata. 
		//   Assign the return value of the method to a variable called asyncResultId of type Id. 
		//   Use null for the callback parameter.
        Id asyncResultId = Metadata.Operations.enqueueDeployment(deployContainer, null);


	}

}