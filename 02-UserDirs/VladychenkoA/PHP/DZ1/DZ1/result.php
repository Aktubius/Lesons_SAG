<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
        "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <title>���������</title>
</head>
<body>
</br>
<h2 align="center">���� �������</h2>
</br>
</br>
<div align="center" >
 <div    style=" font-size:16px;width:250px; padding:10px; background:#00FFFF">

<?php
/**
 * Created by PhpStorm.
 * User: ���������
 * Date: 06.02.2011
 * Time: 19:27:35
 * To change this template use File | Settings | File Templates.
 */
if($_POST["submit"])
 {
     $Count = 7;
     $begin = 1;
     $productNumber = 0;
     $Product = 0;
     $order = 0.0;

     for($i = $begin; $i < $Count; $i++)
     {
         $productTmp = (int)$_POST["product".$i];
         $productPrice = $_POST["price".$i];

        if($productTmp && $productPrice)
         {
             if(is_int($productTmp) && ($productTmp > 0))
             {
                 $Product++;
             }

           $productNumber += $productTmp;

           $DoublePrice = str_replace(",",".",$productPrice);
           $order += $productTmp*$DoublePrice;

           $productTmp =0;
           $productPrice = 0;
         }
     }
if($order > 0)
echo   "�������. �� ��������� ".$productNumber.'<br>'
      ."  ������� ( ".$Product." �������(-��)) �� ����� ".'<br>'
        .$order;
else
    echo " �� ������ �� ������.".'<br>'.
        "������� �� �������� � ������ �������";
 }

?>
    </div></div>
<div align="center">
<form action="index.php" method="post">
    <input align="center"   type="submit" value="���������" >
</form>
</div>
</body>
</html>