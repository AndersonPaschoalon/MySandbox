function createProdCheckbox(outFormName, checkboxClassName, checkboxId, yes_value, no_value, productName) {
	// create the form
    var theForm = document.createElement("FORM");
    theForm.setAttribute("id", outFormName);
    // Create Product text
    var prodText = document.createElement("text"); 
	var newContentProd = document.createTextNode(productName); 
	prodText.appendChild(newContentProd); 
    // create Yes box
    var yes_box = document.createElement("input");
    yes_box.setAttribute("class", checkboxClassName);
    yes_box.setAttribute("type", "checkbox");
    yes_box.setAttribute("id", checkboxId+"-yes");
    yes_box.setAttribute("value", yes_value);
	// Create yes text
    var yesText = document.createElement("text"); 
	var newContentYes = document.createTextNode("Yes "); 
	yesText.appendChild(newContentYes); 
    // create No box
    var no_box = document.createElement("input");
    no_box.setAttribute("class", checkboxClassName);
    no_box.setAttribute("type", "checkbox");
    no_box.setAttribute("id", checkboxId+"-no");
    no_box.setAttribute("value", no_value);
	// Create No text
    var noText = document.createElement("text"); 
	var newContentNo = document.createTextNode("No "); 
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

function csvToVect(csvEntry, strDelimiter)
{
    var vecIn = csvEntry.split(strDelimiter);
    return vecIn;	
}

function createFormulary(csvList)
{
	var fullFormId = 'outside-form-id';
	var checkButtonClass = 'dynamic-yes-no-check';
	var checkboxIdPrefix = 'checkbox-';
	
	csvVec = csvToVect(csvList, ",");
	for(var i = 0; i<csvVec.length; i++)
	{
    	createProdCheckbox(fullFormId, checkButtonClass, checkboxIdPrefix+i, 'yes-value', 'no-value', csvVec[i]);
	}
}

function formularyFromHtmlCsv(elementId)
{
	var csvIn = document.getElementById(elementId).innerHTML;
    createFormulary(csvIn);
}

//create a Csv List of values from checkbox on the HTML page. It assumes that
//the checkbox Ids have this format: idPrefix+Counter+idSufix
//idPrefix: id prefix from the form
//idSufix: id sufix from the form
//number of forms in the page
//if you want the checked(true) or unchecked(false) boxes
function csvFromIdValues(idPrefix, idSufix, numberOfIds, checkedCondition) 
{
	isChecked = Boolean(checkedCondition);
	var csvString="";
	for(var i=0; i<numberOfIds; i++)
	{
		var theValue = document.getElementById(idPrefix+i+idSufix).value;
		var checkedStatus = document.getElementById(idPrefix+i+idSufix).checked;
		if(isChecked==checkedStatus) 
		{
			if(i==0)
			{
				csvString += theValue;
			}
			else
			{
				csvString += ", "+theValue;
			}
		}
	}
	return csvString;
}

//Just set the Csvs on the right ids
//eg: setSubmitCsvForm("yes-form", "teste1", "no-form", "teste2", "blank-form", "teste3")
function setSubmitCsvForm(formYesId, csvYes, formNoId, csvNo, formBlankId, csvBlank)
{
	document.getElementById(formYesId).innerHTML = csvYes;
	document.getElementById(formNoId).innerHTML = csvNo;
	document.getElementById(formBlankId).innerHTML = csvBlank;
}

//main function
formularyFromHtmlCsv("csv-input-id");
document.getElementById("checkbox-2-yes").checked = true;
var elementExists = document.getElementById("checkbox-2-yes");
if(elementExists==null)
{
	alert("crap");
}
else
{
	alert(elementExists.checked);
}

/*
Pseudocode:

onload:
numberBoxes = formularyFromHtmlCsv("csv-input-id"); //ok
checkFormulary("csv-yes-list-id"); //todo

onSubmit:
csvYes = csvFromIdValues("checkbox-", "-yes", numberBoxes/2, true); //ok
csvNo = csvFromIdValues("checkbox-", "-no", numberBoxes/2, true); 
csvBlankYes = csvFromIdValues("checkbox-", "-yes", numberBoxes, false); //ok
csvBlankNo = csvFromIdValues("checkbox-", "-no", numberBoxes, false); //ok
csvBlank = csvBlankYes+", "+csvBlankNo; //ok
setSubmitCsvForm(formYesId, csvYes, formNoId, csvNo, formBlankId, csvBlank); //ok
 */

//document.getElementById('some-id-2-yes').cheked = True;