/*�� ������������ ��������� ������ ���. ����������, ����� �������� ��������
 ���� ������������ �� ������� ������������ ��������. 
������������� ��������� ������� ����� �������, ����� ����, �������� � �����.
 ��� ������� ����� ������ � �������� � ���� ������.*/
//----------
var arr = Array("First name", "Second name", "Third name");
var edit = Array("edit1","edit2","edit3");
var simbol = String(" .abcdefghgklnopqrstuvwxyzABCDEFGHGKLNOPQRSTUVWXYZ������������������������������������������Ȩ������������������ڲ�");
//----------
function check(editField,elpos) {
	var len = editField.value.length;	
	if((len > 0)||(editField.value.charAt(0) == " ")&&(len == 1)) {
	  for(var i = 0; i < len; ++i) {
			if(simbol.indexOf(	editField.value.charAt(i))== -1) {
				alert("Field " + arr[elpos] + " have bad simbol in word " + editField.value + " in position " + i);		
				return true;
			} else {
				return false;
			}
	  }
	} else {
		alert("Field " + arr[elpos] + " is empty");
	}
}
//----------
function checkFields() {
	for(var i = 0; i < 3; ++i) {
		check(document.getElementById(edit[i]), i);		
	}
}
//----------