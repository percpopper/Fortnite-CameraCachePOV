
char __fastcall DefaultCase(char* a1, uint8* a2)
{
	int v2; // esi
	uint8* v3; // rbx
	char* v5; // rdi
	__int64 v6; // rcx
	__int64 v7; // rdi
	int v8; // edx
	char v9; // al
	char result; // al
	char v11; // al
	int v12; // edx
	__int64 v13; // r8
	char v14; // al

	v2 = 0;
	v3 = a2;

	BYTE GoofyCondition = *(BYTE*)(BaseAddress + 0xEA78D08);

	if (GoofyCondition)
	{
		v5 = a1 + 6;
		v6 = 52i64;
		v7 = (uint8*)v5 - a2;
		v8 = 0xDF8508E9;
		do
		{
			v9 = v8;
			v8 += 11;
			result = v3[v7] ^ v9;
			*v3++ = result;
			--v6;
		} while (v6);
	}
	else
	{
		v11 = *a1;
		v12 = 0x2D5CD7;
		v13 = *((uint64*)a1 + 1) + 52i64 - (uint64)v3;
		do
		{
			v14 = v12;
			v12 ^= v2 ^ 0xFEDCBA98;
			result = (v3[v13] ^ v14) - v2++;
			*v3++ = result;
		} while (v2 < 52);
	}
	return result;
}

FMinimalViewInfo* __fastcall DecryptViewInfo(uint8 CameraIndexMaybe)
{
	__int64 v2; // r14
	int v3; // esi
	uint8* v4; // rbx
	char* v5; // rdi
	char v6; // al
	__int64 v7; // r10
	char v8; // r9
	int v9; // eax
	char v10; // cl
	int v11; // eax
	uint8* v12; // rdi
	__int64 v13; // r8
	__int64 v14; // rbx
	__int64 v15; // r8
	__int64 v16; // rdi
	char v17; // al
	__int64 v18; // r9
	int v19; // edx
	int v20; // eax
	int v21; // ecx
	__int64 v22; // rdi
	__int64 v23; // r8
	char v24; // al
	char v25; // al
	__int64 v26; // r8
	int v27; // edx
	__int64 v28; // rcx
	char v29; // al

	v2 = 0x7C0i64 * CameraIndexMaybe;

	v3 = 0;

	uint64 CameraDataPtr = *(uint64*)(BaseAddress + 0xECF2460);

	uint64 v5e = *(uint64*)(BaseAddress + 0xECF2470);

	v4 = (uint8*)CameraDataPtr + v2;

	v5 = (char*)v5e + 72 * CameraIndexMaybe;

	BYTE CameraSwitch = *(BYTE*)(BaseAddress + 0xEA78D48);

	if (CameraSwitch)
	{
		switch (CameraSwitch)
		{
		case 1:
			v21 = 0xA87D8528;
			v22 = (uint8*)v5 + 6 - v4;
			v23 = 52i64;
			do
			{
				v24 = v21;
				v21 -= 9;
				*v4 = v4[v22] ^ v24;
				++v4;
				--v23;
			} while (v23);
			break;
		case 2:
			v17 = *v5;
			v18 = *((uint64*)v5 + 1);
			v19 = 0xB7F7DDF;
			do
			{
				*v4 = *(uint8*)(26 * ((v3 & 1u) + 1) - (unsigned __int64)(unsigned int)v3 + v18 + 52) - v19;
				v20 = 16 * v3++;
				++v4;
				v19 ^= ~v20;
			} while (v3 < 52);
			break;
		case 3:
			v15 = 52i64;
			v16 = (uint8*)v5 + 6 - v4;
			do
			{
				*v4 = __ROL1__(v4[v16], 4);
				++v4;
				--v15;
			} while (v15);
			break;
		case 4:
			v12 = (uint8*)v5 + 1;
			v13 = 52i64;
			v14 = v4 - v12;
			do
			{
				v12[v14] = *v12 + ~v12[5];
				++v12;
				--v13;
			} while (v13);
			break;
		case 5:
			v6 = *v5;
			v7 = *((uint64*)v5 + 1);
			v8 = 53;
			do
			{
				v9 = 52;
				v10 = v8;
				if (v3 % 3u != 1)
					v9 = 104;
				v8 += 17;
				v11 = v3 + v9;
				++v3;
				*v4++ = *(uint8*)(v11 + v7) ^ v10;
			} while (v3 < 52);
			break;
		default:
			uint64 a = *(uint64*)(BaseAddress + 0xECF2460);
			DefaultCase(v5, (uint8*)a + v2);
			break;
		}
	}
	else
	{
		v25 = *v5;
		v26 = 52i64;
		v27 = 0x192FFE89;
		v28 = *((uint64*)v5 + 1) + 52i64 - (uint64)v4;
		do
		{
			v29 = v27;
			v27 += v3;
			v3 += 16;
			*v4 = v4[v28] ^ v29;
			++v4;
			--v26;
		} while (v26);
	}

	uint64 L = *(uint64*)(BaseAddress + 0xECF2460);

	return reinterpret_cast<FMinimalViewInfo*>(L + v3);
}
