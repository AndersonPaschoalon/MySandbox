/*
TODO list:
- [ok] create an After subimit landing page
- just one yes/no checked by product 
- list of blanks, now it is not working
- [done] form to subimit values to the next page
- create a formulary product-based from the list of YES options
- group producsts by region using a class in the outer form 
- group the outher form inside a colapse form 
- create N colapses forms based in a list of regions
- replace all vars per let
*/

/**
 * [public] onclick function to create a CSV in a input box. 
 */
function checkboxRunOnClick()
{
	// ****properties*****
	let outTagIdYes = "choices-products-yes";
	let outTagIdNo = "choices-products-no";
	let outTagIdBlank = "choices-products-blank";
	let classNameYes = "dynamic-yes";
	let classNameNo = "dynamic-no";
	let delimiter = ",";
	
	putOnHtmlFromFormulary(outTagIdYes, outTagIdNo, outTagIdBlank, 
	classNameYes, classNameNo, delimiter);
}


/**
 * [public] Create a YES/NO formulary from a list of producs csvList inside an
 * HTML tag.
 * @example 
 * formularyFromHtmlCsv("tag-name"); 
 * @param {String} elementId - tag name
 */
function formularyFromHtmlCsv(elementId) {
	let csvIn = document.getElementById(elementId).innerHTML;
	let csvLen = createFormulary(csvIn);
	//return csvLen;
}

/** 
 * [public] Convert a CSV string to an array 
 * @example 
 * let csvArray = csvToArray("value1, value2, value3", ",") // csvArray.length is 3
 * @param {String} csvEntry - String in CSV format 
 * @param {String} csvDelimiter - CSV delimiter. Eg.: "," or ";"
 * @returns {Array} arrayCsv - created array 
 */
function csvToArray(csvEntry, csvDelimiter) 
{
	let arrayCsv = csvEntry.split(csvDelimiter);
	return arrayCsv;
}

/**
 * Takes as input a html tag Id, which contains a a CSV list of values, and tricks a 
 * checkbox formulary of a given class 
 @example
 */
function tickFormularyFromHtmlCsv(htmlTagId, className)
{
	// **** properties *****
	let csvDelimiter = ',';

	let arrayCsvValues = csvToArray(document.getElementById(htmlTagId).innerHTML, csvDelimiter);
	tickCheckboxesByValue2(arrayCsvValues, className);
} 

// * TODO blank need to work right
//
function putOnHtmlFromFormulary(outTagIdYes, outTagIdNo, outTagIdBlank, 
	classNameYes, classNameNo, delimiter)
{
	let csvIschekedYes = csvFromCheckboxValues(classNameYes, true, delimiter);
	let csvIschekedNo = csvFromCheckboxValues(classNameNo, true, delimiter);

	let csvNotchekedYes = csvFromCheckboxValues(classNameYes, false, delimiter);
	let csvNotchekedNo = csvFromCheckboxValues(classNameNo, false, delimiter);

	//document.getElementById(outTagIdYes).innerHTML = csvIschekedYes;
	//document.getElementById(outTagIdNo).innerHTML = csvIschekedNo;
	//document.getElementById(outTagIdBlank).innerHTML = 'TODO';
	document.getElementById(outTagIdYes).value = csvIschekedYes;
	document.getElementById(outTagIdNo).value = csvIschekedNo;
	document.getElementById(outTagIdBlank).value = 'TODO';
}



/** deprecated **********************
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
	let fullFormId = 'outside-form-id';
	let checkButtonYesClass = 'dynamic-yes';
	let checkButtonNoClass = 'dynamic-no';
	let checkboxIdPrefix = 'checkbox-';
	let csvDelimiter = ',';

	csvVec = csvToArray(csvList, csvDelimiter);
	for (let i = 0; i < csvVec.length; i++) {
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
	let yes_text = "Yes ";
	let no_text = "No ";
	let yes_sufix = "-yes";
	let no_sufix = "-no";
	let runOnClickFunction = "checkboxRunOnClick()";

	// create the form
	let theForm = document.createElement("FORM");
	theForm.setAttribute("id", outFormName);
	// Create Product text
	let prodText = document.createElement("text");
	let newContentProd = document.createTextNode(productName);
	prodText.appendChild(newContentProd);
	// create Yes box
	let yes_box = document.createElement("input");
	yes_box.setAttribute("class", checkboxYesClassName);
	yes_box.setAttribute("type", "checkbox");
	yes_box.setAttribute("id", checkboxId + yes_sufix);
	yes_box.setAttribute("value", yes_value);
	yes_box.setAttribute("onclick", runOnClickFunction);
	// Create yes text
	let yesText = document.createElement("text");
	let newContentYes = document.createTextNode(yes_text);
	yesText.appendChild(newContentYes);
	// create No box
	let no_box = document.createElement("input");
	no_box.setAttribute("class", checkboxNoClassName);
	no_box.setAttribute("type", "checkbox");
	no_box.setAttribute("id", checkboxId + no_sufix);
	no_box.setAttribute("value", no_value);
	no_box.setAttribute("onclick", runOnClickFunction);
	// Create No text
	let noText = document.createElement("text");
	let newContentNo = document.createTextNode(no_text);
	noText.appendChild(newContentNo);
	// create line break
	let lineBreak1 = document.createElement("br");
	let lineBreak2 = document.createElement("br");
	let lineBreak3 = document.createElement("br");

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
	let csvString = "";
	for ( let i = 0; i < numberOfIds; i++) {
		let theValue = document.getElementById(idPrefix + i + idSufix).value;
		let checkedStatus = document.getElementById(idPrefix + i + idSufix).checked;
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
	let i = 0;
	let idValuesMatch = [];
	for (i = 0; i < vecIds.length; i++) {
		let idValue = document.getElementById(vecIds[i]).value;
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
	let i = 0;
	let idValuesMatch = [];
	let elements = document.getElementsByClassName(className);
	console.log("elements.length="+elements.length);
	console.log("vecValues=$"+vecValues+'$');
	for (i = 0; i < elements.length; i++) 
	{
		console.log("elements["+i+"].value=$"+elements[i].value+"$");
		if (vecValues.includes(elements[i].value)){
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
 * CSV delimiter, returns a list of values
 */
function csvFromCheckboxValues(className, checkedCondition, delimiter)
{
	let isChecked = Boolean(checkedCondition);
	console.log('csvFromCheckboxValues(): isChecked='+isChecked);
	let elements = document.getElementsByClassName(className); 

	let arrayOfChoices = [];
	for(let i=0; i<elements.length; i++)
	{
		if(elements[i].checked==checkedCondition)
		{
			arrayOfChoices.push(elements[i].value);
		}
	}
	console.log('# arrayOfChoices: ='+arrayOfChoices);	

	let csvString = '';
	for(let i=0; i<arrayOfChoices.length; i++)
	{
		if(i==(arrayOfChoices.length-1)){
			csvString += arrayOfChoices[i];
		}
		else
		{
			csvString += arrayOfChoices[i]+delimiter;
		}
	}
	console.log('return: ='+csvString);	
	return csvString;
}



formularyFromHtmlCsv('list-of-products');
tickFormularyFromHtmlCsv('list-of-products-yes', 'dynamic-yes');
tickFormularyFromHtmlCsv('list-of-products-no', 'dynamic-no');  
putOnHtmlFromFormulary('choices-products-yes', 'choices-products-no', 'choices-products-blank', 
	'dynamic-yes', 'dynamic-no', ',')

/*
no_csvcheked = csvFromCheckboxValues('dynamic-no', true, ',');
yes_csvcheked = csvFromCheckboxValues('dynamic-yes', true, ',');
no_csvNotcheked = csvFromCheckboxValues('dynamic-no', false, ',');
yes_csvNotcheked = csvFromCheckboxValues('dynamic-yes', false, ',');
document.getElementById('debug').innerHTML+=" #no_csvcheked: $"+no_csvcheked+"$"+"<br>";
document.getElementById('debug').innerHTML+=" #yes_csvcheked: $"+yes_csvcheked+"$"+"<br>";
document.getElementById('debug').innerHTML+=" #no_csvNotcheked: $"+no_csvNotcheked+"$"+"<br>";
document.getElementById('debug').innerHTML+=" #yes_csvNotcheked: $"+yes_csvNotcheked+"$"+"<br>";
*/