char __fastcall DefaultCase(char* a1, uint8* a2)
{
	int v3; // esi
	uint8* v4; // rbx
	char* v6; // rdi
	__int64 v7; // rcx
	__int64 v8; // rdi
	int v9; // edx
	char v10; // al
	char result; // al
	char v12; // al
	int v13; // edx
	__int64 v14; // r8
	char v15; // al

	v3 = 0;
	v4 = a2;

	BYTE CameraSwitch = *(BYTE*)(BaseAddress + 0xEA7AD00);

	if (CameraSwitch)
	{
		v6 = a1 + 6;
		v7 = 52i64;
		v8 = (uint8*)v6 - a2;
		v9 = -544805623;
		do
		{
			v10 = v9;
			v9 += 11;
			result = v4[v8] ^ v10;
			*v4++ = result;
			--v7;
		} while (v7);
	}
	else
	{
		v12 = *a1;
		v13 = 2957419;
		v14 = *((uint64*)a1 + 1) + 52i64 - (uint64)v4;
		do
		{
			v15 = v13;
			v13 ^= v3 ^ 0xFEDCBA98;
			result = (v4[v14] ^ v15) - v3++;
			*v4++ = result;
		} while (v3 < 52);
	}
	return result;
}

FMinimalViewInfo* __fastcall FullDecryptViewInfo(uint8 CameraIndexMaybe)
{
	int v2; // esi
	__int64 v3; // r14
	uint8* CameraData; // rbx
	char* v5; // rdi
	unsigned int v6; // edx
	__int64 v7; // rdi
	__int64 v8; // rcx
	char v9; // al
	char v10; // al
	unsigned int v11; // r8d
	__int64 v12; // rcx
	__int64 v13; // rdx
	char v14; // al
	uint8* v15; // rdi
	__int64 v16; // rcx
	__int64 v17; // rbx
	uint8* v18; // rdi
	__int64 v19; // rcx
	__int64 v20; // rbx
	__int64 v21; // rcx
	__int64 v22; // rdi
	char v23; // al
	__int64 v24; // rcx
	int v25; // edx
	__int64 v26; // r8
	char v27; // al

	BYTE CameraSwitch = *(BYTE*)(BaseAddress + 0xEA7AD40);

	v2 = 0;

	v3 = 0x7C0i64 * CameraIndexMaybe;

	uint64 CameraDataPtr = *(uint64*)(BaseAddress + 0xECF43A0);

	CameraData = (uint8*)(CameraDataPtr + v3);

	uint64 c = *(uint64*)(BaseAddress + 0xECF43B0);

	v5 = (char*)(c + 0x48 * CameraIndexMaybe);

	if (CameraSwitch)
	{
		switch (CameraSwitch)
		{
		case 1:
			v21 = 0x34i64;
			v22 = (uint8*)v5 + 6 - CameraData;
			do
			{
				*CameraData = __ROL1__(CameraData[v22], 4);
				++CameraData;
				--v21;
			} while (v21);
			break;
		case 2:
			v18 = (uint8*)v5 + 1;
			v19 = 0x34i64;
			v20 = CameraData - v18;
			do
			{
				v18[v20] = *v18 + ~v18[5];
				++v18;
				--v19;
			} while (v19);
			break;
		case 3:
			v15 = (uint8*)v5 + 6;
			v16 = 52i64;
			v17 = CameraData - v15;
			do
			{
				v15[v17] = *v15 ^ *(v15 - 5);
				++v15;
				--v16;
			} while (v16);
			break;
		case 4:
			v10 = *v5;
			v11 = 0xBF85ED58;
			v12 = 0x34i64;
			v13 = *((uint64*)v5 + 1) + 104i64 - (uint64)CameraData;
			do
			{
				v14 = CameraData[v13] - v11;
				v11 += 5;
				*CameraData++ = ~v14;
				--v12;
			} while (v12);
			break;
		case 5:
			v6 = 0xA87E60C8;
			v7 = (uint8*)v5 + 6 - CameraData;
			v8 = 52i64;
			do
			{
				v9 = v6;
				v6 -= 9;
				*CameraData = CameraData[v7] ^ v9;
				++CameraData;
				--v8;
			} while (v8);
			break;
		default:
			uint64 a = *(uint64*)(BaseAddress + 0xECF43A0);
			uint64 b = *(uint64*)(BaseAddress + 0xECF43B0);
			DefaultCase((char*)b + 0x48 * CameraIndexMaybe, (uint8*)a + v3);
			break;
		}
	}
	else
	{
		v23 = *v5;
		v24 = 52i64;
		v25 = 0x192C1B69;
		v26 = *((uint64*)v5 + 1) + 52i64 - (uint64)CameraData;
		do
		{
			v27 = v25;
			v25 += v2;
			v2 += 16;
			*CameraData = CameraData[v26] ^ v27;
			++CameraData;
			--v24;
		} while (v24);
	}

	uint64 L = *(uint64*)(BaseAddress + 0xECF43A0);

	return reinterpret_cast<FMinimalViewInfo*>(L + v3);
}
