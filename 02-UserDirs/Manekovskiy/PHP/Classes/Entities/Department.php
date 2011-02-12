<?php
/**
 * Created by PhpStorm.
 * User: rasik
 * Date: 12 ��� 2011
 * Time: 12:20:36
 * To change this template use File | Settings | File Templates.
 */
 
class Department
{
    private $name;
    private $employees;
    private $manager;

    function __construct($name, $employees, $manager)
    {
        // TODO: �������� �������� �� ���� � ������� � � ��������� $manager
        if(is_string($name) &&
           is_array($employees) &&
           is_object($manager))
        {
            $this -> name = $name;
            $this -> employees = $employees; // TODO: ��������� $this -> employees ������������ id => employee
            $this -> manager = $manager;
            
            $this -> manager -> setDepartment($this); // IoC!
        }
    }

    function getEmployees()
    {
        return $this -> employees;
    }
}
