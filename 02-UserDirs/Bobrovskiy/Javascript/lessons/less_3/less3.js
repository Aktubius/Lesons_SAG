// ����������� ������� "���������" 
function Engine (cil, v) {
    this.cilCount = cil;
    this.v = v;
    return this;
}
// ����������� ������� "����������" 
function Automobile (aVendorName, aModel, nCil, V) {
    this.vendor = aVendorName;
    this.model = aModel;
    this.engine = new Engine (nCil, V);
    this.getInfo = autoInfo;

    return this;
}
function autoInfo() {
    alert ("�������������: "+this.vendor+"\n"+
           "������: "+this.model+"\n"+
           "���������: "+this.engine.cilCount+"���. ����� "+this.engine.v+"�.\n"); 
}

//var myAuto = new Automobile("Wolkswagen", "Corolla", 4, 1.8);
//myAuto.getInfo();

