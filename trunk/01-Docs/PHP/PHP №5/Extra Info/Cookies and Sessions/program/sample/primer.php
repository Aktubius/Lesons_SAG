<?php
//c�������� �������� ���� ������� ����������� �� �����
//��� ��� �������� ��� ������� ��� ������ � ����� ������
if(isset($id)){
	header("Content-type:image/gif");//������� header ��������� ������� � �������� ��������� 
	//HTTP �������������� ������
	$r = mysql_connect();
	mysql_select_db("primer", $r);
	$query = "select picture from first where id=".$id;
	$res = mysql_query($query);
	if(mysql_num_rows($res)){
		$ar = mysql_fetch_row($res);
		echo $ar[0];
	}
}

//� ������ ����� ���� �� ��������� ������������ ��� ����������� 
//� ���� ������
if(isset($ufile)){
	if($ufile_type == "image/gif" || $ufile_type == "image/jpg" || $ufile_type == "image/png"){
		$f = fopen($ufile, "rb");
		while(!feof($f))
			$u = fread($f, 65000);
		fclose($f);
		$r = mysql_connect();
		mysql_select_db("primer", $r);	
		$query = "insert into first (id, name, picture) values (NULL, '".$ufile_name."', '".$u."')";
		mysql_query($query);
		mysql_close();
	}
	else {
		echo "���������� ���� ���� �� �������� ��������!<br>";
	}
}

//����� �� ������� �� ����� ���������� ����� �������
	$r = mysql_connect();
	mysql_select_db("primer", $r);
	$query = "select * from first";
	$res = mysql_query($query);
	echo "<table border=1>";
	if($m = mysql_num_rows($res)){
		for($i = 0; $i < $m; $i++){
			$ar = mysql_fetch_row($res);
			echo "<tr><td>".$ar[0]."</td><td>".$ar[1]."</td><td><a href=primer.php?id=".$ar[0].">�������� �������</a></td></tr>";
		}
	}
	echo "</table>";
	mysql_close();	
	
?>
