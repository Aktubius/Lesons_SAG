/*� �������� ��������� ������� ��� ������������ 
"�������� ���� �������"! � ��� ��� ����� �����������? �� web-��������
 ����������� 2 ������. � ������� ������ ������� �����, �������������� 
 ��������� �����������: 
���� ������ 
�������� �������� � ������ ����� ��� ����� ���� 
������� ����� � ������ �� ������� ������� ������� ������ 
��������� �������� �������� � ������ ������ 
���� ����������� ��������� ������� ��� �����: 
*/
//----------
var sitehist = new Array();
var currenturl = new String();
//-------
function setCurrentUrl() {
	currenturl = form1.elements["textfield"].value;
}
function getCurrentUrl() {
	return currenturl;
}
function loadCurrnetUrl() {
	parent.frames["bottomFrame"].location.replace(getCurrentUrl());
}
function loadCurrentUrlinNewWindow() {
	window.open(getCurrentUrl(),"_blank");
}
//-------
function Op() {
	if (!form1.elements["checkbox"].checked) {
		setCurrentUrl();
	     loadCurrnetUrl();
	      sitehist.push(getCurrentUrl());
	  }
	else {
		setCurrentUrl();
	     loadCurrentUrlinNewWindow();
		  sitehist.push(getCurrentUrl());
	  }
}
//---
function Forward() {
	form1.elements["textfield"].value = sitehist.shift();
	 sitehist.push(form1.elements["textfield"].value);
	 
	 parent.frames["bottomFrame"].location.replace(form1.elements["textfield"].value);	
}
//---
function Back() {
   form1.elements["textfield"].value = sitehist.pop();
     sitehist.unshift(form1.elements["textfield"].value);
	 
	parent.frames["bottomFrame"].location.replace(form1.elements["textfield"].value);	
}
//----------
