# Performance: stock vs candidate

| metric | stock median (us) | cand median (us) | ratio | stock noise | margin | runs s/c | verdict |
|---|---:|---:|---:|---:|---:|---|---|
| 2d.get_config.sel1 | 3.54 | 3.48 | 0.983 | 3.4 % | 10.2 % | 5/5 | OK |
| 2d.get_surface_info.sel2 | 3.72 | 3.72 | 1.000 | 2.4 % | 7.3 % | 5/5 | OK |
| 2d.read_regs_1.sel16 | 4.29 | 4.32 | 1.007 | 1.4 % | 5.0 % | 5/5 | OK |
| 2d.read_regs_2.sel16 | 4.74 | 4.74 | 1.000 | 2.5 % | 7.6 % | 5/5 | OK |
| dvd.check_stamps.sel20 | 3.48 | 3.57 | 1.026 | 1.7 % | 5.2 % | 5/5 | OK |
| dvd.get_config.sel1 | 3.48 | 3.54 | 1.017 | 2.6 % | 7.8 % | 5/5 | OK |
| dvd.get_status.sel2 | 3.45 | 3.57 | 1.035 | 2.6 % | 7.8 % | 5/5 | OK |
| dvd.read_regs.sel13 | 4.29 | 4.32 | 1.007 | 2.1 % | 6.3 % | 5/5 | OK |
| gl.get_config.sel3 | 3.69 | 3.66 | 0.992 | 2.4 % | 7.3 % | 5/5 | OK |
| gl.get_hw_info.sel20 | 3.60 | 3.63 | 1.008 | 4.2 % | 12.5 % | 5/5 | OK |
| gl.get_status.sel4 | 3.63 | 3.57 | 0.983 | 3.3 % | 9.9 % | 5/5 | OK |
| glcycle.ChoosePixelFormat | 33.00 | 33.00 | 1.000 | 0.0 % | 5.0 % | 5/5 | OK |
| glcycle.Clear+Flush | 191.00 | 197.00 | 1.031 | 1.0 % | 5.0 % | 5/5 | OK |
| glcycle.CreateContext | 1973.00 | 1957.00 | 0.992 | 0.9 % | 5.0 % | 5/5 | OK |
| glcycle.Draw100Tri+Flush | 187.00 | 189.00 | 1.011 | 1.1 % | 5.0 % | 5/5 | OK |
| glcycle.ReadPixels | 1488.00 | 1495.00 | 1.005 | 6.1 % | 18.3 % | 5/5 | OK |
| glcycle.SetPBuffer | 1928.00 | 1913.00 | 0.992 | 1.0 % | 5.0 % | 5/5 | OK |
| glcycle.Teardown | 982.00 | 959.00 | 0.977 | 1.0 % | 5.0 % | 5/5 | OK |
| open_close.2d | 98.65 | 97.51 | 0.988 | 1.2 % | 5.0 % | 5/5 | OK |
| open_close.dvd | 159.73 | 163.06 | 1.021 | 1.3 % | 5.0 % | 5/5 | OK |
| open_close.gl | 292.16 | 289.25 | 0.990 | 0.9 % | 5.0 % | 5/5 | OK |
| open_close.surface | 61.86 | 59.40 | 0.960 | 1.2 % | 5.0 % | 5/5 | OK |
| surface.get_state.sel2 | 3.54 | 3.60 | 1.017 | 2.5 % | 7.6 % | 5/5 | OK |
| surface.query_lock.sel11 | 3.63 | 3.60 | 0.992 | 1.7 % | 5.0 % | 5/5 | OK |

Totals: OK 24
