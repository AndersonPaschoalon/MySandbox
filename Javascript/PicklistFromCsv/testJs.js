/**
 * Method to be used to make colapsable forms work.
 * Eg.:
 * <button class="collapsible">Open Section 2</button>
 * <div class="content">
 * <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>
 * </div>
 * EventListenerColapse("collapsible");
 */
function EventListenerColapse(collapsibleClassName)
{
    let coll = document.getElementsByClassName(collapsibleClassName);
    let i;
    for (i = 0; i < coll.length; i++) {
        coll[i].addEventListener("click", function() {
            this.classList.toggle("active");
            var content = this.nextElementSibling;
            if (content.style.display === "block") {
                content.style.display = "none";
            } else {
                content.style.display = "block";
            }
        });
    }
}

function CollapsableDiv(ButtonLabel, divId, ButtonClass, ContentDivClass)
{
		let theDiv = document.createElement("span");
    	theDiv.setAttribute("id", divId);

		let buttonForm = document.createElement("button");
		buttonForm.innerHTML = ButtonLabel;
		buttonForm.setAttribute("class", ButtonClass);

		let contentForm = document.createElement("div");
		contentForm.setAttribute("class", ContentDivClass);
		contentForm.setAttribute("style", "display:block");
		contentForm.innerHTML = "TEST TEST dfgfgffffffffffffffffffffffffffff ";

		theDiv.appendChild(buttonForm);
		theDiv.appendChild(contentForm);
	
		this.Div_ButtonClass = ButtonClass;
		this.Div_ContentDivClass = ContentDivClass;
		this.Div_divId = divId;
		this.Div_ButtonLabel = ButtonLabel;
		this.Div_CollapsableDiv= theDiv;
		return theDiv;
}
CollapsableDiv.prototype.addForm = function(theForm){
	let childNodesList = this.Div_CollapsableDiv.childNodes;
	
}


function runOnClickFunction()
{
	alert('Hellow');	
}


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


function ProdCheckbox(outFormName, productName, checkboxId, checkboxClassName,
	checkbox_value, runOnClickFunction, text_style)
{

	let theForm = document.createElement("FORM");
    theForm.setAttribute("id", outFormName);

	let prodText = document.createElement("span");
	prodText.style = text_style;
	prodText.innerHTML = productName;

	let checkbox_form = document.createElement("input");
    checkbox_form.setAttribute("type", "checkbox");
	checkbox_form.setAttribute("class", checkboxClassName);
	checkbox_form.setAttribute("id", checkboxId);
	checkbox_form.setAttribute("value", checkbox_value);
	checkbox_form.setAttribute("onclick", runOnClickFunction);    

	theForm.appendChild(prodText);
	theForm.appendChild(checkbox_form);
	return theForm;
}



document.body.appendChild(
 ProdCheckboxYesNo("outFormName", "ProdTest ", "checkboxId", "checkboxYesClassName", "yes_id_sufix", 
	"yes_value", "Yes ", "checkboxNoClassName", "no_id_sufix", "no_value", "No ", "runOnClickFunction()", "font-weight:bold")
);

document.body.appendChild(
 ProdCheckbox("outFormName", "Product2", "checkboxId2", "checkboxClassName",
	"checkbox_value", "runOnClickFunction()", "font-weight:bold")
);

document.body.appendChild(
	CollapsableDiv("The Test", "collapsibleFormId", "collapsible", "content")
);

EventListenerColapse("collapsible");