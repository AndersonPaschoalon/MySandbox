/**
 * public: create a YES/NO formulary from a list of producs csvList inside an
 * HTML tag
 */
function formularyFromHtmlCsv(elementId) {
	var csvIn = document.getElementById(elementId).innerHTML;
	var csvLen = createFormulary(csvIn);
	return csvLen;
}

/** 
 * public: Convert a CSV to array 
 */
function csvToVect(csvEntry, strDelimiter) 
{
	csvIn =  csvEntry.replace(/ /g,'')
	var vecIn = csvIn.split(strDelimiter);
	return vecIn;
}


/**
 * 
 */
function tickFormularyFromHtmlCsv(htmlTagId, className)
{
	// **** properties *****
	var csvDelimiter = ",";

	var csvValues = document.getElementById(htmlTagId).innerHTML;
	var valuesArray = csvToVect(csvValues, csvDelimiter);
	tickCheckboxesByValue2(valuesArray, className);
} 

function putOnHtmlFromFormulary(outTagIdYes, outTagIdNo, outTagIdBlank, 
	classNameYes, classNameNo, delimiter)
{
	var csvIschekedYes = csvFromCheckboxValues(classNameYes, true, delimiter);
	console.log("csvIschekedYes="+csvIschekedYes);

	var csvIschekedNo = csvFromCheckboxValues(classNameNo, true, delimiter);
	console.log("csvIschekedNo="+csvIschekedNo);

	var csvNotchekedYes = csvFromCheckboxValues(classNameYes, false, delimiter);
	console.log("csvNotchekedYes="+csvNotchekedYes);

	var csvNotchekedNo = csvFromCheckboxValues(classNameNo, false, delimiter);
	console.log("csvNotchekedNo="+csvNotchekedNo);

	var csvBlank = csvNotchekedYes+delimiter+csvNotchekedNo;
	console.log("csvBlank"+csvBlank);


	document.getElementById(outTagIdYes).innerHTML = csvIschekedYes;
	document.getElementById(outTagIdNo).innerHTML = csvIschekedNo;
	document.getElementById(outTagIdBlank).innerHTML = csvBlank;
}



/**
 * public:  Just set the Csvs on the right ids on a set HTML forms
 * eg: setSubmitCsvForm("yes-form", "teste1", "no-form", "teste2", "blank-form",
 * "teste3")
 */
function setSubmitCsvForm(formYesId, csvYes, formNoId, csvNo, formBlankId,
		csvBlank) {
	document.getElementById(formYesId).innerHTML = csvYes;
	document.getElementById(formNoId).innerHTML = csvNo;
	document.getElementById(formBlankId).innerHTML = csvBlank;
}

/** 
 * private: create a YES/NO formulary from a list of producs csvList 
 */
function createFormulary(csvList) {
	// properties
	var fullFormId = 'outside-form-id';
	var checkButtonYesClass = 'dynamic-yes';
	var checkButtonNoClass = 'dynamic-no';
	var checkboxIdPrefix = 'checkbox-';

	csvVec = csvToVect(csvList, ",");
	for ( var i = 0; i < csvVec.length; i++) {
		createProdCheckbox(fullFormId, checkButtonYesClass, checkButtonNoClass, checkboxIdPrefix + i,
				csvVec[i], csvVec[i], csvVec[i]);
	}
	return csvVec.length;
}

/**
 * private: This functions create a Yes/No checkbox, with the out form ID 
 * outFormName, checkbox class checkboxClassName, Id checkboxId, value of 
 * Yes yes_value, No value no_value, and with the label productName
 */
function createProdCheckbox(outFormName, checkboxYesClassName, checkboxNoClassName, checkboxId,
		yes_value, no_value, productName) {
	// properties
	var yes_text = "Yes ";
	var no_text = "No ";
	var yes_sufix = "-yes";
	var no_sufix = "-no";

	// create the form
	var theForm = document.createElement("FORM");
	theForm.setAttribute("id", outFormName);
	// Create Product text
	var prodText = document.createElement("text");
	var newContentProd = document.createTextNode(productName);
	prodText.appendChild(newContentProd);
	// create Yes box
	var yes_box = document.createElement("input");
	yes_box.setAttribute("class", checkboxYesClassName);
	yes_box.setAttribute("type", "checkbox");
	yes_box.setAttribute("id", checkboxId + yes_sufix);
	yes_box.setAttribute("value", yes_value);
	// Create yes text
	var yesText = document.createElement("text");
	var newContentYes = document.createTextNode(yes_text);
	yesText.appendChild(newContentYes);
	// create No box
	var no_box = document.createElement("input");
	no_box.setAttribute("class", checkboxNoClassName);
	no_box.setAttribute("type", "checkbox");
	no_box.setAttribute("id", checkboxId + no_sufix);
	no_box.setAttribute("value", no_value);
	// Create No text
	var noText = document.createElement("text");
	var newContentNo = document.createTextNode(no_text);
	noText.appendChild(newContentNo);
	// create line break
	var lineBreak1 = document.createElement("br");
	var lineBreak2 = document.createElement("br");
	var lineBreak3 = document.createElement("br");

	// create form
	document.body.appendChild(theForm);
	document.getElementById(outFormName).appendChild(prodText);
	document.getElementById(outFormName).appendChild(lineBreak1);
	document.getElementById(outFormName).appendChild(yes_box);
	document.getElementById(outFormName).appendChild(yesText);
	document.getElementById(outFormName).appendChild(no_box);
	document.getElementById(outFormName).appendChild(noText);
	document.getElementById(outFormName).appendChild(lineBreak2);
	document.getElementById(outFormName).appendChild(lineBreak3);
}

/** ******deprecated 
 * create a Csv List of values from checkbox on the HTML page. It assumes that
 * the checkbox Ids have this format: idPrefix+Counter+idSufix
 * idPrefix: id prefix from the form
 * idSufix: id sufix from the form
 * number of forms in the page
 * if you want the checked(true) or unchecked(false) boxes
 */
function csvFromIdValues(idPrefix, idSufix, numberOfIds, checkedCondition) {
	isChecked = Boolean(checkedCondition);
	var csvString = "";
	for ( var i = 0; i < numberOfIds; i++) {
		var theValue = document.getElementById(idPrefix + i + idSufix).value;
		var checkedStatus = document.getElementById(idPrefix + i + idSufix).checked;
		if (isChecked == checkedStatus) {
			if (i == 0) {
				csvString += theValue;
			} else {
				csvString += "," + theValue;
			}
		}
	}
	return csvString;
}
 
/** *********** deprecated
 * private: This function takes as parameter two arrays: on of values and one of ids. If
 * checks all the forms with the ids an the list. If the form has one of the
 * values listed on the values vector, the property "checked" is set as true
 */
function tickCheckboxesByValue(vecValues, vecIds) {
	var i = 0;
	var idValuesMatch = [];
	for (i = 0; i < vecIds.length; i++) {
		var idValue = document.getElementById(vecIds[i]).value;
		if (vecValues.includes(idValue)) {
			idValuesMatch.push(vecIds[i]);
		}
	}
	for (i = 0; i < idValuesMatch.length; i++) {
		document.getElementById(idValuesMatch[i]).checked = true;
	}
}

/**
 * private:  This function takes as parameter: an array of valid values, and a a class
 * name. if the element of this class  has one of this values, it is checked as
 * true
 */
function tickCheckboxesByValue2(vecValues, className) 
{
	console.log("## tickCheckboxesByValue2() ##");
	var i = 0;
	var idValuesMatch = [];
	var elements = document.getElementsByClassName(className);
	console.log("elements.length="+elements.length);
	console.log("vecValues="+vecValues);
	for (i = 0; i < elements.length; i++) 
	{
		console.log("elements["+i+"].value="+elements[i].value);
		if (vecValues.includes(elements[i].value)) 
		{

			idValuesMatch.push(elements[i].id);
		}
	}
	console.log("idValuesMatch="+idValuesMatch);
	for (i = 0; i < idValuesMatch.length; i++) {
		document.getElementById(idValuesMatch[i]).checked = true;
	}
}








/**
 * private: given a class name, checkbox condition (true/false) and a 
 * CSV separator, returns a list of values
 */
function csvFromCheckboxValues(className, checkedCondition, separator)
{
	var isChecked = Boolean(checkedCondition);
	console.log('csvFromCheckboxValues(): isChecked='+isChecked);
	
	var elements = document.getElementsByClassName(className); 

	// debug start 
	//for(var i = 0; i< elements.length; i++)
	//{
	//	console.log("* Checkbox status: "+elements[i].value+" checked="+elements[i].checked);
	//	console.log('* csvFromCheckboxValues(): elements[i].id='+elements[i].id);
	//}
	// debug end

	var arrayOfChoises = [];
	for(var i=0; i<elements.length; i++)
	{
		if(elements[i].checked==checkedCondition)
		{
			arrayOfChoises.push(elements[i].value);
		}
	}
	console.log('# arrayOfChoises: ='+arrayOfChoises);	

	var csvString = '';
	for(var i=0; i<arrayOfChoises.length; i++)
	{
		if(i==(arrayOfChoises.length-1)){
			csvString += arrayOfChoises[i];
		}
		else
		{
			csvString += arrayOfChoises[i]+separator;
		}
	}

	console.log('retunr: ='+csvString);	
	return csvString;
}




/*
 * var tickFormularyFromCsvList(csvListId, numberOfCheckboxes) { // properties
 * var idPrefix = "checkbox-"; var idSufix = "-yes";
 * 
 * vecIds = []; for(var i = 0; i<numberOfCheckboxes; i++) {
 * vecIds.push(idPrefix+i+idSufix); }
 * 
 * var csvList = document.getElementById(csvListId).innerHtml; var
 * arrayValuesTick = csvToVect(csvList); tickCheckboxesByValue(arrayValuesTick,
 * vecIds);
 *  }
 */

// Creates a formulary form a list of itens inside an HTML tag
//var csvLen = formularyFromHtmlCsv("list-of-products");
// tick a set of checkboxes based on its class name and its tag value
// this accepts a set ov valid values and a class 
//tickCheckboxesByValue2(["prod1", "prod2", "prod6", "invalidProd"], "dynamic-yes");


//var arrayProd = csvToVect("prod1, prod2, prod3");
//document.getElementById("debug").innerHTML = csvLen;
//var ids = [ "checkbox-1-yes", "checkbox-1-no", "checkbox-3-no" ];
// tickCheckboxesByValue(vecValues, vecIds)


//tickFormularyFromHtmlCsv("list-of-products-yes", 'dynamic-yes');
//tickFormularyFromHtmlCsv("list-of-products-no", 'dynamic-no');

//csvIscheked = csvFromCheckboxValues("dynamic-yes", true, ",");
//document.getElementById("debug").innerHTML+=" Checked Values: "+csvIscheked+"########";
csvIscheked = csvFromCheckboxValues('dynamic-no', false, ',');
document.getElementById("debug").innerHTML+="Not Checked Values: "+csvIscheked+"########";


//putOnHtmlFromFormulary("choises-products-yes", "choises-products-no", "choises-products-blank", 
//	"dynamic-yes", "dynamic-no", ",");


// var vec_values = ["1","abacate"];
// var vec_ids = ["myCheck1", "myCheck2", "myCheck3", "myCheck4", "myCheck5"];
// tickCheckboxesByValue(vec_values, vec_ids);

/*
 * Pseudocode:
 * 
 * onload: numberBoxes = formularyFromHtmlCsv("csv-input-id"); //ok
 * checkFormulary("csv-yes-list-id"); //todo
 * 
 * onSubmit: csvYes = csvFromIdValues("checkbox-", "-yes", numberBoxes/2, true);
 * //ok csvNo = csvFromIdValues("checkbox-", "-no", numberBoxes/2, true);
 * csvBlankYes = csvFromIdValues("checkbox-", "-yes", numberBoxes, false); //ok
 * csvBlankNo = csvFromIdValues("checkbox-", "-no", numberBoxes, false); //ok
 * csvBlank = csvBlankYes+", "+csvBlankNo; //ok setSubmitCsvForm(formYesId,
 * csvYes, formNoId, csvNo, formBlankId, csvBlank); //ok
 */




var csvLen = formularyFromHtmlCsv("list-of-products");
tickFormularyFromHtmlCsv("list-of-products-yes", 'dynamic-yes');
tickFormularyFromHtmlCsv("list-of-products-no", 'dynamic-no');

no_csvcheked = csvFromCheckboxValues('dynamic-no', true, ',');
yes_csvcheked = csvFromCheckboxValues('dynamic-yes', true, ',');
no_csvNotcheked = csvFromCheckboxValues('dynamic-no', false, ',');
yes_csvNotcheked = csvFromCheckboxValues('dynamic-yes', false, ',');

document.getElementById("debug").innerHTML+=" #no_csvcheked: $"+no_csvcheked+"$"+"<br>";
document.getElementById("debug").innerHTML+=" #yes_csvcheked: $"+yes_csvcheked+"$"+"<br>";
document.getElementById("debug").innerHTML+=" #no_csvNotcheked: $"+no_csvNotcheked+"$"+"<br>";
document.getElementById("debug").innerHTML+=" #yes_csvNotcheked: $"+yes_csvNotcheked+"$"+"<br>";