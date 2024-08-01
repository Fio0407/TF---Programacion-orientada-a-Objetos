#pragma once


namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Lose
	/// </summary>
	public ref class Lose : public System::Windows::Forms::Form
	{
	private:
		//Ost
		SoundPlayer^ ostLose;
	public:
		Lose(void)
		{
			InitializeComponent();
			//SoundPlayer
			ostLose = gcnew SoundPlayer("ost/CancionGameOver.wav");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Lose()
		{
			if (components)
			{
				delete components;
			}
			delete ostLose;
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Lose::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Minecraft", 12));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(255, 331);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(384, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"¡Uy! El juego termino, mejor suerte a la proxima";
			// 
			// Lose
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(912, 565);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(928, 604);
			this->MinimumSize = System::Drawing::Size(928, 604);
			this->Name = L"Lose";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Lose";
			this->Load += gcnew System::EventHandler(this, &Lose::Lose_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Lose_Load(System::Object^ sender, System::EventArgs^ e) {
		ostLose->PlayLooping();
	}
	};
}
