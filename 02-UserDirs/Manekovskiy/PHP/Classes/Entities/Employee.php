<?php

include_once "Person.php";

class Employee extends Person
{
    function __construct()
    {
        parent::__construct("unnamed", 42);
    }
    /*
     * ��� ������� ��������� ������� ������ � �������� ����������
     */
    function work($toDig)
    {
        return $toDig ? "deep hole" : "drink tea";
    }
}

?>
