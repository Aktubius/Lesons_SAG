using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Xml;
using System.Runtime.Remoting;
using System.Net;
using System.Text.RegularExpressions;
using System.Web;

namespace Valute_Light
{
    public partial class ValuteForm : Form
    {
        //������� �����
        private const int valuteNumber = 29;
        
        //������ ������� ���
        private string siteURL = "http://www.bank.gov.ua/Fin_ryn/OF_KURS/Currency/FindByDate.aspx";
        
        //������ ������� ������� ��� ����� ������
        private string[] valuteAmount = 
            { "100", "100", "100", "10", "100", "100", "100", "100", "100", 
              "100", "100", "100", "100", "100", "100", "100", "10", "100", "100", 
              "100", "100", "100", "100", "100", "10", "100", "100", "100", "100", 
              "10000", "1000", "100", "100", "100", "100", "100", "1000"};
        //������ ���� �����
        private string[] valutes = 
            { "������������� ������", "���������������� ������", "���������� ����� ��������", 
              "���������� �����", "�������� ����", "������ ���", "���������� ����", 
              "����", "����������� ����", "�������������� �����", "���������� ������", 
              "���������� ����", "���������� ���", "����������� ���", 
              "���������� ����", "��������� ������", "��������� �����", 
              "������������ ������", "���������� ����", "���", "��������� ��",
              "������������ ������", "��������� �������", "��������� ����", "������� ����",
              "��������� ����", "������������ ������", "���� ��������(�����)", "��������� ��"};
        //������� �������� ����
        //������ ����
        private string[] intValuteIndexes = 
            { "036", "031", "826", "974", "208", "840", "233", "978", "352",
              "398", "124", "428", "440", "498", "578", "985", "643", "702", 
              "703", "960", "792", "795", "348", "860", "203", "752", "756", 
              "156", "392" };
        //������� ����
        private string[] strValuteIndexes = 
            { "AUD", "AZM", "GBP", "BYR", "DKK", "USD", "EEK", "EUR", "ISK", 
              "KZT", "CAD", "LVL", "LTL", "MDL", "NOK", "PLN", "RUB", "SGD", 
              "SKK", "XDR", "TRL", "TMM", "HUF", "UZS", "CZK", "SEK", "CHF", 
              "CNY", "JPY" };

        //���� ��� ������ � ������
        private static DateTime today = DateTime.Now;        //�������
        private static DateTime tomorrow = today.AddDays(1); //������ 
        
        //������ ����� �����
        private double[] todayCurrency = new double[valuteNumber];
        private double[] tomorrowCurrency = new double[valuteNumber];
        
        //���� ���������� ����� � �������
        private bool todayCurrencyAvailable = false;
        private bool tomorrowCurrencyAvailable = false;
        
        //����������� ������� �����
        public ValuteForm()
        {
            InitializeComponent();
            linkLabel.Links[0].LinkData = "www.bank.gov.ua";
            radioToday.Text += string.Format("({0}.{1}.{2})", today.Day, today.Month, today.Year);
            radioTomorrow.Text += string.Format("({0}.{1}.{2})", tomorrow.Day, tomorrow.Month, tomorrow.Year);
            //������������� ������� ������ �� �������
            backgroundWorker.DoWork +=
                new DoWorkEventHandler(BackgroundWorkerDoWork);
            backgroundWorker.RunWorkerCompleted +=
                new RunWorkerCompletedEventHandler(BackgroundWorkerRunWorkerCompleted);
            RefillCurrencyTable(today);
        }

        //������ �����������/��������� ���� ���������� �� ������� ����
        private void GrayControls(bool hide)
        {
            if (hide)
            {
                statusStrip.Items["toolStripStatusLabel"].Visible = true;
                radioToday.Enabled = false;
                radioTomorrow.Enabled = false;
                toolbar.Enabled = false;
                //mainMenu.Enabled = false;
                //todayTomorrowCurrencyTable.Enabled = false;
            }
            else
            {
                statusStrip.Items["toolStripStatusLabel"].Visible = false;
                radioToday.Enabled = true;
                radioTomorrow.Enabled = true;
                toolbar.Enabled = true;
               //mainMenu.Enabled = true;
               //todayTomorrowCurrencyTable.Enabled = true;
            }
        }

        //��������� ���������� � ������� ������
        private void RefillCurrencyTable(DateTime date)
        {
            todayTomorrowCurrencyTable.RowCount = 1;
            for (int i = 0; i < valuteNumber; i++)
                todayTomorrowCurrencyTable.Rows.Add(
                    intValuteIndexes[i],
                    strValuteIndexes[i],
                    valuteAmount[i],
                    valutes[i],
                    Currency(date, i));
        }
        
        //���������� ���� ������ �� ����������� ������(valuteIndex) � ����(date)
        //������������ ������ ��� ��������� ������������/����������� �����
        private double Currency(DateTime date, int valuteIndex)
        {
            if (date == today)
                if (todayCurrencyAvailable)
                    return Convert.ToDouble(todayCurrency[valuteIndex]);
            if (date == tomorrow)
                if (tomorrowCurrencyAvailable)
                    return Convert.ToDouble(tomorrowCurrency[valuteIndex]);
            return 0;
        }

        //������� ���������� 
        //������������ ���� radiotoday, radioTomorrow � exprExchValutePicker
        private void AmountOrDateChanged(object sender, EventArgs e)
        {
            double amount = 0;          //�-�� ������
            double exchangeResult = 0;  //��������� �������� �������

            if (double.TryParse(exprExchValuteAmount.Text, out amount))
            {
                if (radioToday.Checked)
                    if (exprExchValutePicker.SelectedIndex >= 0)
                        exchangeResult = (amount * Currency(today, exprExchValutePicker.SelectedIndex) 
                            / Convert.ToDouble(valuteAmount[exprExchValutePicker.SelectedIndex]));
                if(radioTomorrow.Checked)
                    if (exprExchValutePicker.SelectedIndex >= 0)
                        exchangeResult = (amount * Currency(tomorrow, exprExchValutePicker.SelectedIndex))
                            / Convert.ToDouble(valuteAmount[exprExchValutePicker.SelectedIndex]);
            }
            exprExchValuteResult.Text = Convert.ToString(exchangeResult);
        }

        //���������� ��䳿 OnCheckedChanged �������� radioToday � radioTomorrow
        private void RequestedDateChanged(object sender, EventArgs e)
        {
            if (sender == radioToday)
                RefillCurrencyTable(today);    
            else
                RefillCurrencyTable(tomorrow);
            AmountOrDateChanged(sender, null);
        }

        //���������� ���� � ������ ��.��.����
        private string DateToString(DateTime date)
        {
            if (date.Day < 10)
                if (date.Month < 10)
                    return string.Format("0{0}.0{1}.{2}", date.Day, date.Month, date.Year);
                else
                    return string.Format("0{0}.{1}.{2}", date.Day, date.Month, date.Year);
            else
                if (date.Month < 10)
                    return string.Format("{0}.0{1}.{2}", date.Day, date.Month, date.Year);
                else
                    return string.Format("{0}.{1}.{2}", date.Day, date.Month, date.Year);
        }

        //������������ �� ������� ������� � �������� �����
        private bool DownloadAndParseCurrencyPage(DateTime date)
        {
            System.Net.CookieContainer cookies = new System.Net.CookieContainer();
            //��������� __VIEWSTATE � �������
            string responseData = GetUrlContent(siteURL, null, ref cookies, true);
            if (responseData == string.Empty)
            {
                GrayControls(false);
                return false;
            }
            
            //��������� �������� �� ��������� �����
            string viewState = ExtractViewState(responseData);
            
            //���������� ������ ���������
            string req = String.Format(
                @"curr_gr={0}&Text1={1}&__VIEWSTATE={2}",
                System.Web.HttpUtility.UrlEncode("Gr1"),
                System.Web.HttpUtility.UrlEncode(DateToString(date)),
                viewState);
            //������ ��������� - � ������ ����
            byte[] buffer = System.Text.Encoding.GetEncoding(1251).GetBytes(req);
            
            //�������� ������ � ������ �� ���� date
            string response = GetUrlContent(siteURL, buffer, ref cookies, false);
            if (response == string.Empty) //�������� �� ������� ������� �������
            {
                GrayControls(false);
                return false;
            }
            else //���� ���������� ���� �������� "��������� �������"
            {
                using (StreamWriter writer = new StreamWriter(@"temp.tmp", false, System.Text.Encoding.GetEncoding(1251)))
                {
                    writer.WriteLine(response); //���������� "������" � ���������� ����  
                }
                
                //���������� �������� ����������� �����������
                System.Globalization.CultureInfo oldCultureInfo = System.Threading.Thread.CurrentThread.CurrentCulture;
                //������������ ����������� ����������� �����������
                System.Threading.Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("");
                
                int valuteIndex = 0; //������� ������
                string line = "";    //������ ��� ������ TextReader � ����������� �����
                int lastIdx = 0;     //���. ��� ����� ������   
                double curr;         //"����" ��������� � ������
                
                TextReader reader = new StreamReader("temp.tmp", Encoding.UTF8);
                while (valuteIndex < 29 && line !=null)
                {
                    line = reader.ReadLine();
                    if (line != null)
                    {
                        lastIdx = line.LastIndexOf("</td>");
                        if (lastIdx >= 0)
                            line = line.Remove(lastIdx);
                        lastIdx = line.LastIndexOf(">");
                        if (lastIdx >= 0)
                        {
                            line = line.Substring(lastIdx + 1);
                            if (Double.TryParse(line, out curr))
                            {
                                if (date == today)
                                   todayCurrency[valuteIndex] = curr;
                                else
                                    tomorrowCurrency[valuteIndex] = curr;
                                valuteIndex++;
                            }
                        }
                    }
                }
                reader.Close();
                System.Threading.Thread.CurrentThread.CurrentCulture = oldCultureInfo;
            }
            return true;
        }

        //������������ __VIEWSTATE
        static private string ExtractViewState(string content)
        {
            System.Text.RegularExpressions.Regex _regex =
                new Regex(@"<input[\s\S]+?name=""__VIEWSTATE""[\s\S]+?value=""(?<value>[\s\S]+?)\""[\s\S]*?/>",
                RegexOptions.IgnoreCase | RegexOptions.Compiled);
            System.Text.RegularExpressions.Match _match = _regex.Match(content);
            return System.Web.HttpUtility.UrlEncodeUnicode(_match.Success ? _match.Groups["value"].Value : string.Empty);
        }
        
        //������ ���� ������� - ������� ����� - ������ ������� � string
        static private string GetUrlContent(string url, byte[] paramString, ref CookieContainer cooks, bool useGet)
        {
            HttpWebRequest req = (HttpWebRequest)WebRequest.Create(url);
            req.UserAgent = "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0; .NET CLR 1.1.4322; .NET CLR 2.0.40607)";
            req.CookieContainer = cooks;
            if (!useGet)
            {
                req.Method = "POST";
                // ������ �������, ��� �� ����� ���������� ���������
                req.ContentType = "application/x-www-form-urlencoded";
                // ������� ���� ��������� � ������
                using (Stream reqst = req.GetRequestStream())
                {
                    reqst.Write(paramString, 0, paramString.Length);
                }
            }

            // ���������� ������, �������� �����
            string response;
            try
            {
                using (Stream resst = ((HttpWebResponse)req.GetResponse()).GetResponseStream())
                {
                    response = new StreamReader(resst, Encoding.GetEncoding(1251)).ReadToEnd();
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("�������� �'������� � ��������� �� �������� ������");
                return string.Empty;
            }
            return response;
        }
        
        private void BackgroundWorkerDoWork(object sender, DoWorkEventArgs e)
        {
            if(todayCurrencyAvailable != true)
                if (DownloadAndParseCurrencyPage(today))
                    todayCurrencyAvailable = true;
            if (tomorrowCurrencyAvailable != true)
                if(DownloadAndParseCurrencyPage(tomorrow))
                    tomorrowCurrencyAvailable = true;
        }
              
        private void BackgroundWorkerRunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Error != null)
            {
                string msg = String.Format("�������: {0}", e.Error.Message);
                MessageBox.Show(msg);
            }
            else
            {
                if (radioToday.Checked == true)
                    RefillCurrencyTable(today);
                else
                    RefillCurrencyTable(tomorrow);
            }
            GrayControls(false);    
        }

        //������� ���� ���, ��������� "��-������������" 
        private void linkLabelLinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("www.bank.gov.ua");
        }

        //������ backgroundWorker'a
        private void RefreshClick(object sender, EventArgs e)
        {
            GrayControls(true);
            backgroundWorker.RunWorkerAsync();
        }

        //���...
        private void ShowAboutBox(object sender, EventArgs e)
        {
            char retKey = Convert.ToChar(Keys.Return);
            MessageBox.Show("������������ - �������� ������� \"����� �����\"" + retKey + retKey +
                            "�����: " + retKey +
                            "������� ������� ����� ��� � ʲ� " + retKey +
                            "����� �� - 23 " + retKey +
                            "������������ ��������� ���������", 
                            "����������", 
                            MessageBoxButtons.OK, 
                            MessageBoxIcon.Information);
        }
        
        //���������� ���. � XML
        private void ExportXML(object sender, CancelEventArgs e)
        {
            XmlTextWriter writer = new XmlTextWriter(exportFileDialog.FileName, Encoding.UTF8);
            writer.Formatting = Formatting.Indented;

            writer.WriteStartDocument();
            writer.WriteStartElement("CurrencyTable");
            for (int i = 0; i < valuteNumber; i++)
            {
                writer.WriteStartElement("valute");
                writer.WriteAttributeString("index", intValuteIndexes[i]);
                writer.WriteAttributeString("strindex", strValuteIndexes[i]);
                writer.WriteValue(todayTomorrowCurrencyTable.Rows[i].Cells[4].Value.ToString());
                writer.WriteEndElement();
            }
            writer.WriteEndDocument();
            writer.Close();
        }
        
        //������������ ���. � XML
        private void ImportXML(object sender, CancelEventArgs e)
        {
            todayTomorrowCurrencyTable.RowCount = 1;
            //double currency;
            int i = 0;
            TextReader r = new StreamReader(importFileDialog.FileName, Encoding.UTF8);
            XmlTextReader reader = new XmlTextReader(r);
            reader.ReadToFollowing("valute");
            while(reader.Read())
                if (reader.NodeType == XmlNodeType.Text)
                {
                    //currency = reader.ReadElementContentAsDouble();
                    todayTomorrowCurrencyTable.Rows.Add(
                        intValuteIndexes[i],
                        strValuteIndexes[i],
                        valuteAmount[i],
                        valutes[i],
                        reader.Value);
                    i++;
                }
            reader.Close();
            r.Close();
        }
        
        //������� � XML
        private void FileExportMenuItemClick(object sender, EventArgs e)
        {
            exportFileDialog.ShowDialog();
        }

        //������ � XML
        private void FileImportMenuItemClick(object sender, EventArgs e)
        {
            importFileDialog.ShowDialog();
        }

        //����
        private void FilePrintMenuItemClick(object sender, EventArgs e)
        {
            DialogResult result = printDialog.ShowDialog();
            if (result == DialogResult.OK)
                printDocument.Print();
        }
        
        //�����
        private void Exit(object sender, EventArgs e)
        {
            Application.Exit();
        }

        //���������� ������� �� ����
        private void PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            Font printFont = new Font("Courier New", 10, FontStyle.Regular);
            e.Graphics.PageUnit = GraphicsUnit.Millimeter;

            e.Graphics.DrawString("�������� ���  ˳������ ���  ʳ������ �������  ����� ������                   ����", printFont, Brushes.Black,10,20);
            e.Graphics.DrawString("36            AUD           100                ������������� ������         " + todayTomorrowCurrencyTable.Rows[0].Cells[4].Value,printFont,Brushes.Black, 10, 25);
            e.Graphics.DrawString("31            AZM           100                ���������������� ������       " + todayTomorrowCurrencyTable.Rows[1].Cells[4].Value,printFont,Brushes.Black, 10, 30);
            e.Graphics.DrawString("826           GBP           100                ���������� ����� ��������  " + todayTomorrowCurrencyTable.Rows[2].Cells[4].Value,printFont,Brushes.Black, 10, 35);
            e.Graphics.DrawString("974           BYR           10                 ���������� �����             " + todayTomorrowCurrencyTable.Rows[3].Cells[4].Value,printFont,Brushes.Black, 10, 40);
            e.Graphics.DrawString("208           DKK           100                �������� ����                  " + todayTomorrowCurrencyTable.Rows[4].Cells[4].Value,printFont,Brushes.Black, 10, 45);
            e.Graphics.DrawString("840           USD           100                ������ ���                    " + todayTomorrowCurrencyTable.Rows[5].Cells[4].Value,printFont,Brushes.Black, 10, 50);
            e.Graphics.DrawString("233           EEK           100                ���������� ����                " + todayTomorrowCurrencyTable.Rows[6].Cells[4].Value,printFont,Brushes.Black, 10, 55);
            e.Graphics.DrawString("978           EUR           100                ����                           " + todayTomorrowCurrencyTable.Rows[7].Cells[4].Value,printFont,Brushes.Black, 10, 60);
            e.Graphics.DrawString("352           ISK           100                ����������� ����               " + todayTomorrowCurrencyTable.Rows[8].Cells[4].Value,printFont,Brushes.Black, 10, 65);
            e.Graphics.DrawString("398           KZT           100                �������������� �����           " + todayTomorrowCurrencyTable.Rows[9].Cells[4].Value,printFont,Brushes.Black, 10, 70);
            e.Graphics.DrawString("124           CAD           100                ���������� ������             " + todayTomorrowCurrencyTable.Rows[10].Cells[4].Value,printFont,Brushes.Black, 10, 75);
            e.Graphics.DrawString("428           LVL           100                ���������� ����              " + todayTomorrowCurrencyTable.Rows[11].Cells[4].Value,printFont,Brushes.Black, 10, 80);
            e.Graphics.DrawString("440           LTL           100                ���������� ���               " + todayTomorrowCurrencyTable.Rows[12].Cells[4].Value,printFont,Brushes.Black, 10, 85);
            e.Graphics.DrawString("498           MDL           100                ����������� ���               " + todayTomorrowCurrencyTable.Rows[13].Cells[4].Value,printFont,Brushes.Black, 10, 90);
            e.Graphics.DrawString("578           NOK           100                ���������� ����                " + todayTomorrowCurrencyTable.Rows[14].Cells[4].Value,printFont,Brushes.Black, 10, 95);
            e.Graphics.DrawString("985           PLN           100                ��������� ������               " + todayTomorrowCurrencyTable.Rows[15].Cells[4].Value,printFont,Brushes.Black, 10, 100);
            e.Graphics.DrawString("643           RUB           10                 ��������� �����              " + todayTomorrowCurrencyTable.Rows[16].Cells[4].Value,printFont,Brushes.Black, 10, 105);
            e.Graphics.DrawString("702           SGD           100                ������������ ������          " + todayTomorrowCurrencyTable.Rows[17].Cells[4].Value,printFont,Brushes.Black, 10, 110);
            e.Graphics.DrawString("703           SKK           100                ���������� ����                " + todayTomorrowCurrencyTable.Rows[18].Cells[4].Value, printFont, Brushes.Black, 10, 115);
            e.Graphics.DrawString("960           XDR           100                ���                            " + todayTomorrowCurrencyTable.Rows[19].Cells[4].Value, printFont, Brushes.Black, 10, 120);
            e.Graphics.DrawString("792           TRL           100                ��������� ��                  " + todayTomorrowCurrencyTable.Rows[20].Cells[4].Value, printFont, Brushes.Black, 10, 125);
            e.Graphics.DrawString("795           TMM           10000              ������������ ������           " + todayTomorrowCurrencyTable.Rows[21].Cells[4].Value, printFont, Brushes.Black, 10, 130);
            e.Graphics.DrawString("348           HUF           1000               ��������� �������             " + todayTomorrowCurrencyTable.Rows[22].Cells[4].Value, printFont, Brushes.Black, 10, 135);
            e.Graphics.DrawString("860           UZS           100                ��������� ����                " + todayTomorrowCurrencyTable.Rows[23].Cells[4].Value, printFont, Brushes.Black, 10, 140);
            e.Graphics.DrawString("203           CZK           100                ������� ����                   " + todayTomorrowCurrencyTable.Rows[24].Cells[4].Value, printFont, Brushes.Black, 10, 145);
            e.Graphics.DrawString("752           SEK           100                ��������� ����                 " + todayTomorrowCurrencyTable.Rows[25].Cells[4].Value, printFont, Brushes.Black, 10, 150);
            e.Graphics.DrawString("756           CHF           100                ������������ ������           " + todayTomorrowCurrencyTable.Rows[26].Cells[4].Value, printFont, Brushes.Black, 10, 155);
            e.Graphics.DrawString("156           CNY           100                ���� �������� (�����)       " + todayTomorrowCurrencyTable.Rows[27].Cells[4].Value, printFont, Brushes.Black, 10, 160);
            e.Graphics.DrawString("392           JPY           1000               ��������� ��                   " + todayTomorrowCurrencyTable.Rows[28].Cells[4].Value, printFont, Brushes.Black, 10, 165);

        }
    }
}