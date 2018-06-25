public class Prevent_SOQL_Injection_Challenge {

    public string textOne {get; set;}
    public string textTwo {get; set;}
    public string comparator {get; set;}
    //public string numberOne {get; set;}
    public Integer numberOne {get; set;}

    public List<Supply__c> whereclause_records {get; set;}


    public PageReference stringSearchOne(){
        string query = 'SELECT Id,Name,Quantity__c,Storage_Location__c,Storage_Location__r.Castle__c,Type__c FROM Supply__c';
        string whereClause = '';

        if(textOne != null && textOne!=''){
                //whereClause += 'name like  \'%'+textOne+'%\' ';
                whereClause += 'name like  \'%'+String.escapeSingleQuotes(textOne)+'%\' ';
        }

        if(whereClause != ''){
            whereclause_records = database.query(query+' where '+whereClause+' Limit 10');
        }

        return null;
    }


    public PageReference stringSearchTwo(){
        string query = 'SELECT Id,Name,Quantity__c,Storage_Location__c,Storage_Location__r.Castle__c,Type__c FROM Supply__c';
        string whereClause = '';

        if(textTwo != null && textTwo!=''){
                //whereClause += 'Storage_Location__r.name like  \'%'+textTwo+'%\' ';
                whereClause += 'Storage_Location__r.name like  \'%'+String.escapeSingleQuotes(textTwo)+'%\' ';
        }

        if(whereClause != ''){
            whereclause_records = database.query(query+' where '+whereClause+' Limit 10');
        }

        return null;
    }


    public PageReference numberSearchOne(){
        string query = 'SELECT Id,Name,Quantity__c,Storage_Location__c,Storage_Location__r.Castle__c,Type__c FROM Supply__c';
        string whereClause = '';

        //if(numberOne != null && comparator != null && (comparator == '<' || comparator == '>' || comparator == '=')){
        if(comparator != null && (comparator == '<' || comparator == '>' || comparator == '=')){
            //whereClause += 'Quantity__c '+comparator+' '+numberOne+' ';
            whereClause += 'Quantity__c '+comparator+' '+String.valueOf(numberOne)+' ';
        }

        if(whereClause != ''){
            whereclause_records = database.query(query+' where '+whereClause+' Limit 10');
        }

        return null;
    }

}