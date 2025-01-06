{
	double k = 0.1;
	double N = 10000;
	double a = 1;
	double b = 1;
	double mu = 3;
	double sigma = 0.2;

	double xmin = 0;
	double xmax = 10;
	int Nbin = 100;

	TF1 norm("norm", "[0]*exp(-[1]*x)", xmin, xmax);
	norm.SetParameters(a, b);

	double integral = norm.Integral(xmin, xmax);
	a = 1/integral;

	TF1 myfunc("myfunc","(1-[0])*[1]*[2]*exp(-[3]*x) + [0]*[1]*gaus(4)", xmin, xmax);
	myfunc.SetParameters(k, N, a, b, 1/sqrt(2*TMath::Pi()*sigma*sigma), mu, sigma);

	// myfunc.Draw();

	TH1D h("hist","Histogram from my function",Nbin,xmin,xmax);
	h.FillRandom("myfunc",N);
	h.Draw();

	TFile file("histogramme.root", "RECREATE");
	h.Write();
	file.Close();
}
