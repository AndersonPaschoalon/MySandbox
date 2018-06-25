/**
 * Trailhead: https://trailhead.salesforce.com/pt-BR/trails/force_com_dev_advanced/modules/apex_patterns_dsl/units/apex_patterns_dsl_apply_dl_principles?trailmix_creator_id=00550000006gvuAAAQ&trailmix_id=gri-newemployee
 *-----------------------------------------------------------------------------------------------------------
 *  # Implement a basic Domain class and Apex trigger
 *    Implement a basic Domain class and accompanying Apex trigger with default and update logic 
 *  based upon domain conventions.
 *  * Create a basic Domain class named Accounts that extends fflib_SObjectDomain.
 *  * Create a trigger named AccountsTrigger for Account that calls the fflib_SObjectDomain
 *    triggerHandler method for all trigger methods.
 *  * Implement defaulting logic that executes when a record is inserted and sets the 
 *    Description field to the value `Domain classes rock!`
 *  * Implement update logic that calculates the Levenshtein distance between the phrase
 *    Domain classes rock! and whatever the contents of the Description field is when an 
 *    Account is updated. Use the Apex String method getLevenshteinDistance(stringToCompare)
 *    and store the result in the Annual Revenue field.
 */

//  * Create a trigger named AccountsTrigger for Account that calls the fflib_SObjectDomain
trigger AccountsTrigger on Account (
	after delete, after insert, after update, after undelete, before delete, before insert, before update) 
{
   // Creates Domain class instance and calls appropriate methods
   fflib_SObjectDomain.triggerHandler(Accounts.class);
}