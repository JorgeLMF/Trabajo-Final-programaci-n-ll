#pragma once
#include "Controladora.h"
#include <time.h>
namespace Project64 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			srand(time(NULL));
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			bmpbase = gcnew Bitmap("Imagenes//Base.jpeg");
			bmpbloque = gcnew Bitmap("Imagenes//Bloque.jpeg");
			ccontroladora = new controladora();
			ccontroladora->mapaleatorio();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			
			if (components)
			{
				delete components;
	
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		controladora* ccontroladora;
		Bitmap^ bmpbloque;

			 Bitmap^ bmpbase;
		
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 802);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		
		ccontroladora->dibujo(buffer->Graphics, bmpbase, bmpbloque);
		buffer->Render(g);
	}
	};
}
