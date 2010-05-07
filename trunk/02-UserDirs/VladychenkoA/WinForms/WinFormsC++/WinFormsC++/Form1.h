#pragma once

#include <time.h>
#include <string>
namespace WinFormsC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public enum DayOfTheWeek { ����������� ,�����������, �������, �����, �������, �������, ������ };
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			
			
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  labelDay;

	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->labelDay = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(55, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 41);
			this->label1->TabIndex = 0;
			this->label1->Text = L"12:00:00";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->ForeColor = System::Drawing::Color::Navy;
			this->button1->Location = System::Drawing::Point(110, 94);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->����ToolStripMenuItem, 
				this->������ToolStripMenuItem, this->������ToolStripMenuItem, this->�������ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->�������ToolStripMenuItem, 
				this->�������ToolStripMenuItem, this->toolStripSeparator, this->���������ToolStripMenuItem, this->������������ToolStripMenuItem, 
				this->toolStripSeparator1, this->������ToolStripMenuItem, this->�����������������������ToolStripMenuItem, this->toolStripSeparator2, 
				this->�����ToolStripMenuItem});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"&����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�������ToolStripMenuItem.Image")));
			this->�������ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(233, 22);
			this->�������ToolStripMenuItem->Text = L"&�������";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�������ToolStripMenuItem.Image")));
			this->�������ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(233, 22);
			this->�������ToolStripMenuItem->Text = L"&�������";
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(230, 6);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"���������ToolStripMenuItem.Image")));
			this->���������ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(233, 22);
			this->���������ToolStripMenuItem->Text = L"&���������";
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(233, 22);
			this->������������ToolStripMenuItem->Text = L"��������� &���";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(230, 6);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"������ToolStripMenuItem.Image")));
			this->������ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->������ToolStripMenuItem->Size = System::Drawing::Size(233, 22);
			this->������ToolStripMenuItem->Text = L"&������";
			// 
			// �����������������������ToolStripMenuItem
			// 
			this->�����������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�����������������������ToolStripMenuItem.Image")));
			this->�����������������������ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->�����������������������ToolStripMenuItem->Name = L"�����������������������ToolStripMenuItem";
			this->�����������������������ToolStripMenuItem->Size = System::Drawing::Size(233, 22);
			this->�����������������������ToolStripMenuItem->Text = L"��������������� ���&�����";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(230, 6);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(233, 22);
			this->�����ToolStripMenuItem->Text = L"��&���";
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->��������������ToolStripMenuItem, 
				this->��������������ToolStripMenuItem1, this->toolStripSeparator3, this->��������ToolStripMenuItem, this->����������ToolStripMenuItem, 
				this->�������ToolStripMenuItem, this->toolStripSeparator4, this->�����������ToolStripMenuItem});
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->������ToolStripMenuItem->Text = L"&������";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->��������������ToolStripMenuItem->Text = L"&������ ��������";
			// 
			// ��������������ToolStripMenuItem1
			// 
			this->��������������ToolStripMenuItem1->Name = L"��������������ToolStripMenuItem1";
			this->��������������ToolStripMenuItem1->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y));
			this->��������������ToolStripMenuItem1->Size = System::Drawing::Size(209, 22);
			this->��������������ToolStripMenuItem1->Text = L"&������ ��������";
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(206, 6);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"��������ToolStripMenuItem.Image")));
			this->��������ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->��������ToolStripMenuItem->Text = L"�������&�";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"����������ToolStripMenuItem.Image")));
			this->����������ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->����������ToolStripMenuItem->Text = L"&����������";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"�������ToolStripMenuItem.Image")));
			this->�������ToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->�������ToolStripMenuItem->Text = L"���&����";
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(206, 6);
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->�����������ToolStripMenuItem->Text = L"�������� &���";
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->���������ToolStripMenuItem, 
				this->���������ToolStripMenuItem});
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->������ToolStripMenuItem->Text = L"&������";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->���������ToolStripMenuItem->Text = L"&���������";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->���������ToolStripMenuItem->Text = L"&���������";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->����������ToolStripMenuItem, 
				this->������ToolStripMenuItem, this->�����ToolStripMenuItem, this->toolStripSeparator5, this->����������ToolStripMenuItem});
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"����&���";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->����������ToolStripMenuItem->Text = L"&����������";
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->������ToolStripMenuItem->Text = L"&������";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->�����ToolStripMenuItem->Text = L"&�����";
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(155, 6);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(158, 22);
			this->����������ToolStripMenuItem->Text = L"&� ���������...";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����������ToolStripMenuItem_Click);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(67, 175);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(188, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"DateTime";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label3->Location = System::Drawing::Point(94, 129);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 4;
			this->label3->Text = L"�������";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::ForestGreen;
			this->label4->Location = System::Drawing::Point(94, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 23);
			this->label4->TabIndex = 5;
			this->label4->Text = L"������";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelDay
			// 
			this->labelDay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->labelDay->ForeColor = System::Drawing::Color::MediumVioletRed;
			this->labelDay->Location = System::Drawing::Point(85, 152);
			this->labelDay->Name = L"labelDay";
			this->labelDay->Size = System::Drawing::Size(136, 23);
			this->labelDay->TabIndex = 6;
			this->labelDay->Text = L"Day";
			this->labelDay->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(284, 205);
			this->Controls->Add(this->labelDay);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::Color::SaddleBrown;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WinFormC++Clock";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::String^ Day(DayOfTheWeek type)
	{
      switch(type)
	  {
	  case �����������:
		  return "�����������";
		  break;
	  case �����������:
		  return "�����������";
		  break;
	  case �������:
		  return "�������";
		  break;
	  case �����:
		  return "�����";
		  break;
	  case �������:
		  return "�������";
		  break;
	  case �������:
		  return "�������";
		  break;
	  case ������:
		  return "������";
		  break;
	  default:
		  return "Empty";
	  }
	}
		
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 label1->Text = L"15:00:00";
				  timer1->Enabled = true;
				  timer1->Interval = 1000;
			 }
			
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 System::DateTime dt ;
				 label1->Text = dt.Now.ToLongTimeString();
				 label2->Text = dt.Now.ToLongDateString();
				/* labelDay->Text = dt.Now.DayOfWeek.ToString();*/
				 DayOfTheWeek d = DayOfTheWeek(dt.Now.DayOfWeek);
				 labelDay->Text = Day(d);
				/* int d = (int)dt.Now.DayOfWeek;
				 labelDay->Text = d.ToString();*/
			 }
private: System::Void ����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			
		 }
};
}

