// � 2000 Dmytro Borovsky.

var rows = testTable.children[0].rows;
var max = 0;
var min = 0;

function count() {
	for (var i = 1; i < rows.length; i++)
		if ((rows[i].cells[0].tagName == 'TD') && (rows[i].cells[1])) {
			max += rows[i].cells[0].children[0].score * 1;
				if (rows[i].cells[0].children[0].checked == (testTable.children[0].rows[i].cells[0].children[0].correct == '��'))
					min += rows[i].cells[0].children[0].score * 1;
		}
	max -= min;
}

var	sum = -min;
function check() {
	sum = -min;
	var answers = 0;
	for (var i = 0; i < testTable.children[0].rows.length; i++)
		if (rows[i].cells[0].tagName == 'TD')
			if (rows[i].cells[0].children[0].checked == (rows[i].cells[0].children[0].correct == '��'))
				sum += rows[i].cells[0].children[0].score * 1;
	result.innerText = '������� �� ������� �����, �� ������� ' + Math.round(100 * sum / max) + ' ����' + getMasculineCaseExtention(Math.round(100 * sum / max)) + ' �� 100-��.';
	if (Math.round(100 * sum / max) < 60)
		result.innerHTML += ' ��� ��������������� ���������� ����� ��� ���������� ������� <b>�� �����<\/b> 60<sup style="text-decoration: underline;">��<\/sup> ������. ������������ ��� ��� �������� ����� ����� � ����� �������� �� ������� �����. �����, ������ <a href="..\/common\/test-tips.xml" title="������ �� ������.">�������� ������ �� ����� ������<\/a>.';
	scrollTo(0, result.offsetTop);
	saveResults();
	lockUnlock();
}

function getMasculineCaseExtention(n) {
	n = Math.abs(n);
	if ((n >= 5) && (n <= 20))
		return '��';
	if ((n % 10) == 1)
		return '';
	if ((n % 10) == 0)
		return '��';
	if ((n % 10) <= 4)
		return '�';
	return '��';
}
function saveResults() {
var path;
	if (document.location.href.toLowerCase().indexOf('design') != -1)
		path = 'Design';
	if (document.location.href.toLowerCase().indexOf('hardware') != -1)
		path = 'Hardware';
	if (document.location.href.toLowerCase().indexOf('program') != -1)
		path = 'Programming';
var HTML = document.documentElement.outerHTML;
	HTML = HTML.replace('<SCRIPT', '<NOSCRIPT');
	HTML = HTML.replace('</SCRIPT', '</NOSCRIPT');
	HTML = HTML.replace('<BUTTON', '<NOSCRIPT');
	HTML = HTML.replace('</BUTTON', '</NOSCRIPT');
	HTML = HTML.replace(' onload=count();', '');
var FS = new ActiveXObject('Scripting.FileSystemObject');
var fileName = prompt('������� ���� � ��� ����� ��� ���������� ����������� �����. �� ��������� ���������� �������������� �� ���� A:.', 'A:\\' + path + ' Test Log.html');
	if (fileName) {
	var testResult = FS.CreateTextFile(fileName, true, true);
		testResult.Write(HTML);
		testResult.Close();
	}
}
function lockUnlock() {
var section, result, XML;
	if (document.location.href.toLowerCase().indexOf('design') != -1)
		section = '������';
	if (document.location.href.toLowerCase().indexOf('hardware') != -1)
		section = '�����';
	if (document.location.href.toLowerCase().indexOf('program') != -1)
		section = '��������';

	if (Math.round(100 * sum / max) < 60)
		result = '��'
	else
		result = '���';

	userDataControl.load('���')
var	isValidXML = userDataControl.getAttribute('�����');
	if ((isValidXML == '') || (isValidXML == null)) {
		XML = userData.XMLDocument;
		userData.src = '../common/maindata.src';
	} else {
		XML = new ActiveXObject('Microsoft.XMLDOM');
		XML.loadXML(isValidXML);
	}

	if (XML.childNodes.item(0).childNodes.length < 10) {
		var newNode = XML.createElement('�������')
		with(newNode) {
			setAttribute('�����', '09');
			setAttribute('������', '��');
			setAttribute('�����', '��');
			setAttribute('��������', '��');
			setAttribute(section, result);
		}
		XML.childNodes.item(0).appendChild(newNode);
	} else
		XML.childNodes.item(0).childNodes.item(09).setAttribute(section, result);

	userDataControl.removeAttribute('����09');
	userDataControl.setAttribute('����09', XML.xml);
	userDataControl.save('���');

}

alert('script');