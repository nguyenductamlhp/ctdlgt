class ConDuong {
private:
	int DiemBatDau;
	int DiemKetThuc;
	double ChieuDai;
public:
	ConDuong() {
		DiemBatDau = -1;
		DiemKetThuc = -1;
		ChieuDai = 0;
	}

	ConDuong(int bd, int kt, int dai) {
		DiemBatDau = bd;
		DiemKetThuc = kt;
		ChieuDai = dai;
	}

	int getDiemBatDau() {
		return DiemBatDau;
	}
	int getDiemKetThuc() {
		return DiemKetThuc;
	}
	double getChieuDai() {
		return ChieuDai;
	}

	void setDiemBatDau(int bd) {
		DiemBatDau = bd;
	}
	void setDiemKetThuc(int kt) {
		DiemKetThuc = kt;
	}
	void setChieuDai(double dai) {
		ChieuDai = dai;
	}

	bool isLonger(ConDuong c) {
		if (ChieuDai > c.ChieuDai) {
			return true;
		}
		return false;
	}
};