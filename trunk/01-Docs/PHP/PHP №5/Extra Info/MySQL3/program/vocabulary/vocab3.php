<?php

include("third.htm");
include ("vocfunc.php");

if(isset($add)){
	Addform();	
}
if(isset($plus)){
	Add($plus);
}
if(isset($hide)){
	if(isset($aword)){
		if(isset($trans)){
			AddFunc($hide, $aword, $trans);
		}
		else echo "<h3 style='color:#778899'>������� �������� �����!</h3>";
	}
	else echo "<h3 style='color:#778899'>������� �����!</h3>";
}
if(isset($del)){
	Delform();
}
if(isset($word)){
		Del($word);
}
if(isset($transmis)){
	AddMean($aword, $trans, $lang);
}
if(isset($otransmis)){
	AddWord($aword, $trans, $lang);
}

function Addform(){
?>
<h2 align="center" style="color:#778899">��������:</h2>
<form action="vocab3.php" method="post">
<table align="center">
<tr>
	<td align="right"><input type="radio" name="plus" value="nw" checked></input></td>
	<td>����� �����</td>
</tr><tr>
	<td align="right"><input type="radio" name="plus" value="nm"></input></td>
	<td>����� �������� ������������� �����</td>
</tr><tr>
	<td colspan="2" align="center"><input type="submit" value="��������"  style="BACKGROUND-COLOR: #d3d3d3; BORDER-COLOR: #778899; "></input></td>
</tr>
</table></form>
<?php
}

function Add($plus){
	if($plus == "nw"){?>
<h2 align="center" style="color:#778899">���������� ������ �����:</h2>
<form action="vocab3.php" method="post">
<input type="Hidden" name="hide" value="nw"></input>
<table align="center">
<tr>
	<td>������� ����� �����</td>
	<td><input type="text" name="aword"></input></td>
</tr>
	<td>������� �������� �����</td>
	<td><input type="text" name="trans"></input></td>
<tr>
	<td colspan="2" align="center"><input type="submit" value="��������" style="BACKGROUND-COLOR: #d3d3d3; BORDER-COLOR: #778899; "></input></td>
</tr>
</table></form>	
<?php
	}
	else 
	if($plus == "nm"){?>
<h2 align="center" style="color:#778899">���������� ��������:</h2>
<form action="vocab3.php" method="post">
<input type="Hidden" name="hide" value="nm"></input>
<table align="center">
<tr>
	<td>������� �����</td>
	<td><input type="text" name="aword"></input></td>
</tr>
	<td>������� �������</td>
	<td><input type="text" name="trans"></input></td>
<tr>
	<td colspan="2" align="center"><input type="submit" value="��������"  style="BACKGROUND-COLOR: #d3d3d3; BORDER-COLOR: #778899; "></input></td>
</tr>
</table></form>	
<?php
	}
}

function AddFunc($hide, $aword, $trans){
	if( !(ereg("^[�-��-߸�]{1,}$",$aword)) && (ereg("^[[:alpha:]]{1,}$",$trans))){
		if( !(ereg("^[[:alpha:]]{1,}$",$aword)) && (ereg("^[�-��-߸�]{1,}$",$trans))){
		echo "<h3 style='color:#778899'>���� ����� � ��� �������� ������ ���� ��������!</h3>";
		return;
		}
	}
	$lang = "eng";
	if(ereg("^[�-��-߸�]{1,}$",$aword)){
		$lang = "rus";
	}
	if($hide=="nw"){
		AddWord($aword, $trans, $lang);
	}
	if($hide == "nm"){
		AddMean($aword, $trans, $lang);
	}
}

function Delform(){
?>
<h2 align="center" style="color:#778899">�������:</h2>
<form action="vocab3.php" method="post">
<table align="center">
<tr>
	<td>������� �����</td>
	<td><input type="text" name="word"></input></td>
	<td><input type="submit" value="�������"></input></td>
</tr>
</table></form>
<?php
}

function Del($word){
	Delform();
	echo "<h3 style='color:#778899'>���������� ��������:</h3>";
	if(ereg("^[�-��-߸�]{1,}$",$word)){
		DelRus($word);
	}
	else if(ereg("^[[:alpha:]]{1,}$",$word)){
		DelEng($word);
	}
	else echo "<h3 style='color:#778899'>������� �����!</h3>";
}
?>