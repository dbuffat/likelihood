{
	// Redefine our function
	double k = 0.1;				// Resultat a trouver
	double N = 10000;
	double a = 1;
	double b = 1.3;
	double mu = 4;
	double sigma = 0.15;

	double xmin = 0;
	double xmax = 10;
	int Nbin = 100;

	TF1 norm("norm", "[0]*exp(-[1]*x)", xmin, xmax);
	norm.SetParameters(a, b);

	double integral = norm.Integral(xmin, xmax);
	a = 1/integral;

	TF1 myfunc("myfunc","(1-[0])*[1]*[2]*exp(-[3]*x) + [0]*[1]*gaus(4)", xmin, xmax);
	myfunc.SetParameters(k, N, a, b, 1/sqrt(2*TMath::Pi()*sigma*sigma), mu, sigma);

	// Load the histogram
	TFile *file = new TFile("challenge.root", "READ");
	TH1D *hist_read = (TH1D*)file->Get("data;1");
	TH1D myhist = *hist_read;
	file->Close();

	TCanvas c("c","l vs k",900,700);
	TGraph lvsk;
	int graphindex = 0;

	xmin = 0.0025;
	xmax = 0.0045;

	for(double ind=xmin; ind<xmax; ind+=0.00001)
	{
		// cout<<"GraphIndex = "<<graphindex<<" | k = "<<ind<<" | likelihood = "<<Likelihood(myhist, myfunc, ind)<<endl;
		lvsk.SetPoint(graphindex, ind, Likelihood(myhist, myfunc, ind));
		graphindex++;
	}

	TF1 myfit("myfit", "[0]*x^2 + [1]*x + [2]");

	c.Divide(2,1);
	c.cd(1);
	myhist.Draw();
	c.cd(2);
	gStyle->SetOptFit(1);
	lvsk.Draw();
	lvsk.Fit("myfit");

	double afit = myfit.GetParameter(0);
	double bfit = myfit.GetParameter(1);
	double cfit = myfit.GetParameter(2);

	myfit.SetParameters(afit, bfit, cfit);
	double kmin = myfit.GetMinimumX(xmin, xmax);

	double sigma_k = 1 / sqrt(2*afit);

	cout<<" k = "<<kmin<<" +- "<<sigma_k<<endl;
}

double Likelihood(TH1D hist, TF1 func, double kbis)
{
	// Implementation of the likelihood

	func.SetParameter(0, kbis);

	double l = 0;

	for(int i=1; i<=Nbin; i++)
	{
		double binwidth = hist.GetBinWidth(i);
		double binlowedge = hist.GetBinLowEdge(i);
		double lambda = func.Integral(binlowedge, binlowedge+binwidth);
		int d = hist.GetBinContent(i);
		
		if(TMath::Poisson(d, lambda)<10e-10)
			continue;
		else
			l -= TMath::Log(TMath::Poisson(d, lambda));
	}

	return l;
}
