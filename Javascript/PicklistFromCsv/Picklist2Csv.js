/**
 * Class: creates a form that contain an Yes/no checkbox and a description in front of it 
 * @param {String} outFormName - name of the submit form outside of the checkboxes 
 * @param {String} productName - name of the product in front of the checkboxes 
 * @param {String} checkboxId - Id prefix of the checkboxes
 * @param {String} checkboxYesClassName - class of the checkbox YES
 * @pararm {String} yes_id_sufix - Id sufix of the YES box 
 * @pararm {String} yes_value - value of the YES box
 * @pararm {String} yes_text - text that will appear in front of the NO box
 * @param {String} checkboxYesClassName - class of the checkbox NO
 * @pararm {String} yes_id_sufix - Id sufix of the NO box 
 * @pararm {String} yes_value - value of the NO box
 * @pararm {String} yes_text - text that will appear in front of the NO box
 * @param {String} runOnClickFunction - functiion call to be called on click. Eg.: "runOnClickFunction()"
 * @param {String} text_style - text style . Eg.: "font-weight:bold"
 */
function ProdCheckboxYesNo(outFormName, productName, checkboxId, checkboxYesClassName, yes_id_sufix, 
	yes_value, yes_text, checkboxNoClassName, no_id_sufix, no_value, no_text, runOnClickFunction, text_style)
{

	let theForm = document.createElement("FORM");
    theForm.setAttribute("id", outFormName);
    
	//let prodText = document.createElement("text");
	//let newContentProd = document.createTextNode(productName);
	//prodText.appendChild(newContentProd);
	let prodText = document.createElement("span");
	prodText.style = text_style;
	prodText.innerHTML = productName;

	let yes_box = document.createElement("input");
    yes_box.setAttribute("type", "checkbox");
	yes_box.setAttribute("class", checkboxYesClassName);
	yes_box.setAttribute("id", checkboxId + yes_id_sufix);
	yes_box.setAttribute("value", yes_value);
	yes_box.setAttribute("onclick", runOnClickFunction);    

   	let no_box = document.createElement("input");
	no_box.setAttribute("class", checkboxNoClassName);
	no_box.setAttribute("type", "checkbox");
	no_box.setAttribute("id", checkboxId + no_id_sufix);
	no_box.setAttribute("value", no_value);
	no_box.setAttribute("onclick", runOnClickFunction);

	//let yes_textbox = document.createTextNode(yes_text);
	//let no_textbox = document.createTextNode(no_text);
	let yes_textbox = document.createElement("span");
	yes_textbox.style = text_style;
	yes_textbox.innerHTML = yes_text;
	let no_textbox = document.createElement("span");
	no_textbox.innerHTML = no_text;
	no_textbox.style = text_style;
	
	theForm.appendChild(prodText);
	theForm.appendChild(yes_textbox);
	theForm.appendChild(yes_box);
	theForm.appendChild(no_textbox);
	theForm.appendChild(no_box);
	return theForm;
}

/**
 * Create a singel prduct checkbox  
 */

function ProdCheckbox(outFormName, productName, checkboxId, checkboxClassName,
	checkbox_value, runOnClickFunction, text_style)
{

	this.outForm = document.createElement("FORM");
    this.outForm.setAttribute("id", outFormName);

	this.prodText = document.createElement("span");
	this.prodText.style = text_style;
	this.prodText.innerHTML = productName;

	this.checkbox_form = document.createElement("input");
    this.checkbox_form.setAttribute("type", "checkbox");
	this.checkbox_form.setAttribute("class", checkboxClassName);
	this.checkbox_form.setAttribute("id", checkboxId);
	this.checkbox_form.setAttribute("value", checkbox_value);
	this.checkbox_form.setAttribute("onclick", runOnClickFunction);    

	this.outForm.appendChild(prodText);
	this.outForm.appendChild(checkbox_form);
	return this.outForm;
}


document.body.appendChild(
 ProdCheckboxYesNo("outFormName", "ProdTest ", "checkboxId", "checkboxYesClassName", "yes_id_sufix", 
	"yes_value", "Yes ", "checkboxNoClassName", "no_id_sufix", "no_value", "No ", "runOnClickFunction()", "font-weight:bold")
);

document.body.appendChild(
 ProdCheckbox("outFormName", "Product2", "checkboxId2", "checkboxClassName",
	"checkbox_value", "runOnClickFunction()", "font-weight:bold")
);
