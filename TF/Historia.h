#pragma once

using namespace System::Media;

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historia
	/// </summary>
	public ref class Historia : public System::Windows::Forms::Form
	{
	private:
		//Ost
		SoundPlayer^ historia;
	public:
		Historia(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			historia = gcnew SoundPlayer("ost/EndingSong.wav");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Historia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Historia::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-2, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(893, 491);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Historia::pictureBox1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->label1->Location = System::Drawing::Point(268, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(401, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Y asi, Leorio continuo y continuo plantando arboles";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->label2->Location = System::Drawing::Point(256, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(429, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Hasta que el mundo volvio a ser mas verde que nunca";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->label3->Location = System::Drawing::Point(336, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(266, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Y Nala siguio comiendo su pizza ;)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Minecraft", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(410, 216);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 32);
			this->label4->TabIndex = 4;
			this->label4->Text = L"El Fin";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(256, 270);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(413, 16);
			this->label5->TabIndex = 5;
			this->label5->Text = L"¡Gracias por acompañarnos en esta aventura!";
			// 
			// Historia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 490);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(905, 529);
			this->Name = L"Historia";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Historia";
			this->Load += gcnew System::EventHandler(this, &Historia::Historia_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Historia_Load(System::Object^ sender, System::EventArgs^ e) {
	historia->PlayLooping();
}
};
}
