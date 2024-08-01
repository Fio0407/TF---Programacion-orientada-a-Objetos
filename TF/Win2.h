#pragma once
#include "Historia.h"

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Win2
	/// </summary>
	public ref class Win2 : public System::Windows::Forms::Form
	{
	private:
		//Ost
		SoundPlayer^ ostWin;
	public:
		Win2(void)
		{
			InitializeComponent();
			//SoundPlayer
			ostWin = gcnew SoundPlayer("ost/videoplayback.wav");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Win2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Win2::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(362, 391);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(182, 57);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Win2::button1_Click);
			// 
			// Win2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(912, 565);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(928, 604);
			this->MinimumSize = System::Drawing::Size(928, 604);
			this->Name = L"Win2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Win2";
			this->Load += gcnew System::EventHandler(this, &Win2::Win2_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Win2_Load(System::Object^ sender, System::EventArgs^ e) {
		ostWin->PlayLooping();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Historia^ historia = gcnew Historia();
		this->Hide();
		ostWin->Stop();
		historia->ShowDialog();
		this->Close();
		delete historia;
		
	}
	};
}
