# Performance: stock vs candidate

| metric | stock median (us) | cand median (us) | ratio | stock noise | margin | runs s/c | verdict |
|---|---:|---:|---:|---:|---:|---|---|
| 2d.get_config.sel1 | 3.54 | 3.48 | 0.983 | 1.7 % | 5.1 % | 5/5 | OK |
| 2d.get_surface_info.sel2 | 3.84 | 3.72 | 0.969 | 3.9 % | 11.7 % | 5/5 | OK |
| 2d.read_regs_1.sel16 | 4.41 | 4.32 | 0.980 | 4.1 % | 12.2 % | 5/5 | OK |
| 2d.read_regs_2.sel16 | 4.80 | 4.74 | 0.988 | 2.5 % | 7.5 % | 5/5 | OK |
| dvd.check_stamps.sel20 | 3.51 | 3.57 | 1.017 | 2.6 % | 7.7 % | 5/5 | OK |
| dvd.get_config.sel1 | 3.51 | 3.54 | 1.009 | 1.7 % | 5.1 % | 5/5 | OK |
| dvd.get_status.sel2 | 3.54 | 3.57 | 1.008 | 2.5 % | 7.6 % | 5/5 | OK |
| dvd.read_regs.sel13 | 4.35 | 4.32 | 0.993 | 3.4 % | 10.3 % | 5/5 | OK |
| gl.get_config.sel3 | 3.75 | 3.66 | 0.976 | 2.4 % | 7.2 % | 5/5 | OK |
| gl.get_hw_info.sel20 | 3.69 | 3.63 | 0.984 | 2.4 % | 7.3 % | 5/5 | OK |
| gl.get_status.sel4 | 3.69 | 3.57 | 0.967 | 1.6 % | 5.0 % | 5/5 | OK |
| glcycle.ChoosePixelFormat | 33.00 | 33.00 | 1.000 | 3.0 % | 9.1 % | 5/5 | OK |
| glcycle.Clear+Flush | 191.00 | 197.00 | 1.031 | 1.0 % | 5.0 % | 5/5 | OK |
| glcycle.CreateContext | 1973.00 | 1957.00 | 0.992 | 0.6 % | 5.0 % | 5/5 | OK |
| glcycle.Draw100Tri+Flush | 187.00 | 189.00 | 1.011 | 0.5 % | 5.0 % | 5/5 | OK |
| glcycle.ReadPixels | 1485.00 | 1495.00 | 1.007 | 6.5 % | 19.4 % | 5/5 | OK |
| glcycle.SetPBuffer | 1939.00 | 1913.00 | 0.987 | 0.7 % | 5.0 % | 5/5 | OK |
| glcycle.Teardown | 989.00 | 959.00 | 0.970 | 0.9 % | 5.0 % | 5/5 | OK |
| open_close.2d | 97.30 | 97.51 | 1.002 | 0.6 % | 5.0 % | 5/5 | OK |
| open_close.dvd | 158.14 | 163.06 | 1.031 | 0.4 % | 5.0 % | 5/5 | OK |
| open_close.gl | 289.34 | 289.25 | 1.000 | 0.9 % | 5.0 % | 5/5 | OK |
| open_close.surface | 61.50 | 59.40 | 0.966 | 0.9 % | 5.0 % | 5/5 | OK |
| surface.get_state.sel2 | 3.57 | 3.60 | 1.008 | 0.8 % | 5.0 % | 5/5 | OK |
| surface.query_lock.sel11 | 3.66 | 3.60 | 0.984 | 0.8 % | 5.0 % | 5/5 | OK |

Totals: OK 24
